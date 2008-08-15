#!/usr/bin/perl -w
#
# Copyright (c) 2004 Silicon Graphics, Inc.  All Rights Reserved.
# Copyright (c) 2008 Aconex.  All Rights Reserved.
# 
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
# 
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
# 

use strict;
use PCP::PMDA;
use vars qw( $pmda $response $status $timestamp );

my $delay = 60;	# seconds
my $dbprobe = "/var/lib/pcp/pmdas/pmdadbping/dbprobe.pl $delay";

sub dbping_probe_callback
{
    my $stamp;
    ( $_ ) = @_;
    ($stamp, $response) = split(/\t/);
    if (defined($stamp) && defined($response)) {
	$timestamp = $stamp;
	$status = 0;
    } else {
	$response = -1;
	$status = 1;	# bad result, keep old $timestamp
    }
}

sub dbping_fetch_callback	# must return array of value,status
{
    my ($cluster, $item, $inst) = @_;

    return (PM_ERR_INST, 0) unless ($inst == -1);

    if ($cluster == 0) {
	if ($item == 0)		{ return ($response, 1); }
	elsif ($item == 1)	{ return ($status, 1); }
    }
    elsif ($cluster == 1) {
	if ($item == 2)		{ return ($timestamp, 1); }
	elsif ($item == 3)	{ return ($delay, 1); }
    }
    return (PM_ERR_PMID, 0);
}

sub dbping_store_callback	# must return a single value (scalar context)
{
    my ($cluster, $item, $inst, $val) = @_;
    my $sts = 0;

    if ($cluster == 1 && $item == 3) {
	$delay = $val;
	return 0;
    }
    elsif ( ($cluster == 0 && ($item == 0 || $item == 1))
	|| ($cluster == 1 && $item == 2) ) {
	return PM_ERR_PERMISSION;
    }
    return PM_ERR_PMID;
}

$pmda = PCP::PMDA->new('dbping', 244);

$pmda->add_metric(pmda_pmid(0,0), PM_TYPE_DOUBLE, PM_INDOM_NULL,
		  PM_SEM_INSTANT, pmda_units(0,1,0,0,PM_TIME_SEC,0),
		  'dbping.response_time',
		  'Length of time taken to access the database', undef);
$pmda->add_metric(pmda_pmid(0,1), PM_TYPE_32, PM_INDOM_NULL,
		  PM_SEM_INSTANT, pmda_units(0,0,0,0,0,0),
		  'dbping.status',
		  'Success state of last attempt to ping the database', undef);
$pmda->add_metric(pmda_pmid(1,2), PM_TYPE_STRING, PM_INDOM_NULL,
		  PM_SEM_INSTANT, pmda_units(0,0,0,0,0,0),
		  'dbping.control.timestamp',
		  'Time of last successful database ping', undef);
$pmda->add_metric(pmda_pmid(1,3), PM_TYPE_U32, PM_INDOM_NULL,
		  PM_SEM_INSTANT, pmda_units(0,1,0,0,PM_TIME_SEC,0),
		  'dbping.control.delay',
		  'Time to sleep between database ping attempts', undef);
$pmda->set_fetch_callback( \&dbping_fetch_callback );
$pmda->set_store_callback( \&dbping_store_callback );
$pmda->add_pipe( $dbprobe, \&dbping_probe_callback, 0 );
$pmda->run;

__END__

=head1 NAME
pmdadbping - database response time and availability PMDA

=head1 SYNOPSIS

=head1 DESCRIPTION

The B<dbping> PMDA...

=head1 SEE ALSO

L<PMDA> - the Performance Metrics Domain Agent's documentation

=cut
