#include "wifi_cert_commands.h"
#include "cy_result.h"

/** This function sets up RX UDP traffic stream
 *
 * @param ts        : The pointer to the traffic stream structure @ref traffic_stream_t.
 * @return          : 0 = CY_RSLT_SUCCESS
 *                        CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/
cy_rslt_t cywifi_setup_rx_traffic_stream( traffic_stream_t* ts );


/** This function sets up TX UDP traffic stream
 *
 * @param ts        : The pointer to the traffic stream structure @ref traffic_stream_t.
 * @return          : 0 = CY_RSLT_SUCCESS
 *                        CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/
cy_rslt_t cywifi_setup_tx_traffic_stream ( traffic_stream_t* ts );


/** This function sets up TX and RX transaction UDP traffic stream
 *
 * @param ts        : The pointer to the traffic stream structure @ref traffic_stream_t.
 * @return          : 0 = CY_RSLT_SUCCESS
 *                        CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/
cy_rslt_t cywifi_setup_transactional_traffic_stream( traffic_stream_t * ts);


/** This function sets up ICMP(Ping) traffic
 *
*
 * @param arg         : The pointer to the argument
 * @param ping_stats  : The pointer to the ping statistics
 * @return  cy_rslt_t : 0 = CY_RSLT_SUCCESS
 *                        CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/
cy_rslt_t cywifi_setup_ping_traffic( void *arg, ping_stats_t *ping_stats );


/** This function closes the socket
 *
 * @param socket_handle :  The pointer to socket handle
 * @return   cy_rslt_t  :  0 = CY_RSLT_SUCCESS
 *                             CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/

cy_rslt_t cywifi_close_socket ( void *socket_handle);

/** This function initializes the Secure-Socket layer
 *
 * @return   cy_rslt_t  :  0 = CY_RSLT_SUCCESS
 *                             CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/
cy_rslt_t cysigma_socket_init ( void );

/** This function receives ICMP ping reply
 *
 * @param   sock_hnd   :  The pointer to the socket handle
 * @param   sockaddr   :  The pointer to the socket address
 * @param   ping_stats :  The Pointer to the ping_stats structure
 * @return  cy_rslt_t  :  0 = CY_RSLT_SUCCESS
 *                            CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/
cy_rslt_t wifi_ping_recv( void *sock_hnd, void *sockaddr, ping_stats_t *ping_stats );


/** This function gets native thread priority.
 *
 * @param   ts               :  The pointer to the traffic stream
 * @param   ac_priority      :  The WMM AC priority
 * @param   ac_priority_num  :  The AC priority number (TX/RX)
 * @param   native_priority  :  The pointer to the value of native priority to be returned
 * @return  cy_rslt_t        :  0 = CY_RSLT_SUCCESS
 *                                  CY_RSLT_TYPE_ERROR
 *
 *******************************************************************************/
cy_rslt_t cywifi_get_native_priority( traffic_stream_t *ts , int ac_priority, int ac_priority_num, int *native_priority);
