/*
 * Library-specific error messages.
 * Copyright (C) 2018  Cumulus Networks, Inc.
 *                     Donald Sharp
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; see the file COPYING; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "lib_errors.h"

/* clang-format off */
static struct log_ref ferr_lib_warn[] = {
	{
		.code = EC_LIB_SNMP,
		.title = "SNMP has discovered a warning",
		.description = "The SNMP AgentX library has returned a warning that we should report to the end user",
		.suggestion = "Gather Log data and open an Issue.",
	},
	{
		.code = EC_LIB_STREAM,
		.title = "The stream subsystem has encountered an error",
		.description = "During sanity checking stream.c has detected an error in the data associated with a particular stream",
		.suggestion = "Gather log data and open an Issue, restart FRR",
	},
	{
		.code = EC_LIB_LINUX_NS,
		.title = "The Linux namespace subsystem has encountered a parsing error",
		.description = "During system startup an invalid parameter for the namesapce was give to FRR",
		.suggestion = "Gather log data and open an Issue. restart FRR",
	},
	{
		.code = EC_LIB_SLOW_THREAD,
		.title = "The Event subsystem has detected a slow process",
		.description = "The Event subsystem has detected a slow process, this typically indicates that FRR is having trouble completing work in a timely manner.  This can be either a misconfiguration, bug, or some combination therof.",
		.suggestion = "Gather log data and open an Issue",
	},
	{
		.code = EC_LIB_RMAP_RECURSION_LIMIT,
		.title = "Reached the Route-Map Recursion Limit",
		.description = "The Route-Map subsystem has detected a route-map depth of RMAP_RECURSION_LIMIT and has stopped processing",
		.suggestion = "Re-work the Route-Map in question to not have so many route-map statements, or recompile FRR with a higher limit",
	},
	{
		.code = EC_LIB_BACKUP_CONFIG,
		.title = "Unable to open configuration file",
		.description = "The config subsystem attempted to read in it's configuration file which failed, so we are falling back to the backup config file to see if it is available",
		.suggestion = "Create configuration file",
	},
	{
		.code = EC_LIB_VRF_LENGTH,
		.title = "The VRF subsystem has encountered a parsing error",
		.description = "The VRF subsystem, during initialization, has found a parsing error with input it has received",
		.suggestion = "Check the length of the vrf name and adjust accordingly",
	},
	{
		.code = END_FERR,
	},
};

static struct log_ref ferr_lib_err[] = {
	{
		.code = EC_LIB_PRIVILEGES,
		.title = "Failure to raise or lower privileges",
		.description = "FRR attempted to raise or lower its privileges and was unable to do so",
		.suggestion = "Ensure that you are running FRR as the frr user and that the user has sufficient privileges to properly access root privileges"
	},
	{
		.code = EC_LIB_VRF_START,
		.title = "VRF Failure on Start",
		.description = "Upon startup FRR failed to properly initialize and startup the VRF subsystem",
		.suggestion = "Ensure that there is sufficient memory to start processes and restart FRR",
	},
	{
		.code = EC_LIB_SOCKET,
		.title = "Socket Error",
		.description = "When attempting to access a socket a system error has occured and we were unable to properly complete the request",
		.suggestion = "Ensure that there are sufficient system resources available and ensure that the frr user has sufficient permisions to work.  If necessary open an Issue",
	},
	{
		.code = EC_LIB_ZAPI_MISSMATCH,
		.title = "ZAPI Error",
		.description = "A version miss-match has been detected between zebra and client protocol",
		.suggestion = "Two different versions of FRR have been installed and the install is not properly setup.  Completely stop FRR, remove it from the system and reinstall.  Typically only developers should see this issue."
	},
	{
		.code = EC_LIB_ZAPI_ENCODE,
		.title = "ZAPI Error",
		.description = "The ZAPI subsystem has detected an encoding issue, between zebra and a client protocol",
		.suggestion = "Gather data and open an Issue, also Restart FRR"
	},
	{
		.code = EC_LIB_ZAPI_SOCKET,
		.title = "ZAPI Error",
		.description = "The ZAPI subsystem has detected a socket error between zebra and a client",
		.suggestion = "Restart FRR"
	},
	{
		.code = EC_LIB_SYSTEM_CALL,
		.title = "System Call Error",
		.description = "FRR has detected a error from using a vital system call and has probably already exited",
		.suggestion = "Ensure permissions are correct for FRR files, users and groups are correct. Additionally check that sufficient system resources are available."
	},
	{
		.code = EC_LIB_VTY,
		.title = "VTY Subsystem Error",
		.description = "FRR has detected a problem with the specified configuration file",
		.suggestion = "Ensure configuration file exists and has correct permissions for operations Additionally ensure that all config lines are correct as well",
	},
	{
		.code = EC_LIB_INTERFACE,
		.title = "Interface Subsystem Error",
		.description = "FRR has detected a problem with interface data from the kernel as it deviates from what we would expect to happen via normal netlink messaging",
		.suggestion = "Open an Issue with all relevant log files and restart FRR"
	},
	{
		.code = EC_LIB_NS,
		.title = "NameSpace Subsystem Error",
		.description = "FRR has detected a problem with NameSpace data from the kernel as it deviates from what we would expect to happen via normal kernel messaging",
		.suggestion = "Open an Issue with all relevant log files and restart FRR"
	},
	{
		.code = EC_LIB_DEVELOPMENT,
		.title = "Developmental Escape Error",
		.description = "FRR has detected an issue where new development has not properly updated all code paths.",
		.suggestion = "Open an Issue with all relevant log files"
	},
	{
		.code = EC_LIB_ZMQ,
		.title = "ZMQ Subsystem Error",
		.description = "FRR has detected an issue with the Zero MQ subsystem and ZeroMQ is not working properly now",
		.suggestion = "Open an Issue with all relevant log files and restart FRR"
	},
	{
		.code = EC_LIB_UNAVAILABLE,
		.title = "Feature or system unavailable",
		.description = "FRR was not compiled with support for a particular feature, or it is not available on the current platform",
		.suggestion = "Recompile FRR with the feature enabled, or find out what platforms support the feature"
	},
	{
		.code = END_FERR,
	}
};
/* clang-format on */

void lib_error_init(void)
{
	log_ref_add(ferr_lib_warn);
	log_ref_add(ferr_lib_err);
}
