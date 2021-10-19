/** Application interface header file */
#include "cy_result.h"

/**
 * \defgroup group_wifi_cert_tester_api_functions Functions
 */

/**
 * \addtogroup group_wifi_cert_tester_api_functions
 * \{
 * * The wifi-cert middleware init API is not thread-safe
 * * The below API is a blocking call
 */


/** This function initializes the wifi-cert middleware library by initializing following
 *   * i.   Initializes the sigma-dut object
 *   * ii.  Initializes the WiFi by downloading WiFi F/W
 *   * iii. Initializes the Secure socket library
 *   * iv.  Adds wifi-cert commands to the command console table.
 *
 * @return cy_rslt_t : CY_RSLT_SUCCESS
 *                   : CY_RSLT_MW_ERROR
  *******************************************************************************/
cy_rslt_t cywifi_init_sigmadut ( void );

/** \} group_wifi_cert_tester_api_functions */
