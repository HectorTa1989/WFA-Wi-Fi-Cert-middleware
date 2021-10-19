#ifndef WIFICERT_NO_HARDWARE
#include "lwipopts.h"
#include "lwip/sockets.h"
#include "lwip/etharp.h"
#include "lwip/ethip6.h"
#include "lwip/icmp.h"
#include "lwip/prot/ip4.h"
#endif
#include "wifi_cert_commands.h"
#include "wifi_traffic_api.h"
#include <stdlib.h>

ping_stats_t ping_stats;

int udp_rx( traffic_stream_t* ts )
{   
    int retval;    
    retval = cywifi_setup_rx_traffic_stream(ts);    
    return retval;
}

int udp_tx ( traffic_stream_t* ts )
{
    int retval;
    cy_rtos_delay_milliseconds(SIGMA_AGENT_DELAY_1MS);
    retval = cywifi_setup_tx_traffic_stream(ts);    
    return retval;	
}

int udp_transactional( traffic_stream_t* ts )
{
    int retval;    
    retval = cywifi_setup_transactional_traffic_stream(ts);    
    return retval;	
}

/*!
 ******************************************************************************
 * Implementation of traffic send ping (with stripped down set of arguments)
 * Sends ICMP pings to the indicated host or IP address
 * argv[0]: traffic_send_ping
 * argv[1]: IP address of target
 * argv[2]: frame size
 * argv[3]: frame rate
 * argv[4]: duration
 * @return  0 for success, otherwise error
 */
int wifi_traffic_send_ping( void *arg )
{
    cywifi_setup_ping_traffic(arg, &ping_stats);
    return 0;
}

/*!
 ******************************************************************************
 * Return value of num_ping_requests and num_ping_replies
 * @return  0 for success, otherwise error
 */

int wifi_traffic_stop_ping( void )
{
    printf("\nstatus,COMPLETE,sent,%u,replies,%u\n", (unsigned int)ping_stats.num_ping_requests,(unsigned int)ping_stats.num_ping_replies);
    return 0;
}

/**
 *  Prepare the contents of an echo ICMP request packet
 *
 *  @param iecho          : Pointer to an icmp_echo_hdr structure in which the ICMP packet will be constructed
 *  @param len            : The length in bytes of the packet buffer passed to the iecho parameter
 *  @param ping_seqnum    : The Ping sequence number
 *
 */

void wifi_ping_prepare_echo( icmp_echo_hdr_t *iecho, int len, uint16_t ping_seqnum )
{
	int i;
    ICMPH_TYPE_SET( iecho, ICMP_ECHO );
    ICMPH_CODE_SET( iecho, 0 );
    iecho->chksum = 0;
    iecho->id = PING_ID;
    iecho->seqno = htons(ping_seqnum );

    /* fill the additional data buffer with some data */
    for ( i = 0; i < (len - (int)sizeof(struct icmp_echo_hdr)); i++ )
    {
        ( (char*) iecho )[sizeof(struct icmp_echo_hdr) + i] = i;
    }
    iecho->chksum = inet_chksum( iecho, len );
}
