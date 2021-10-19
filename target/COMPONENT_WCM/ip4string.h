#ifndef IP4STRING_H
#define IP4STRING_H
#ifdef __cplusplus
extern "C" {
#endif

#include "ns_types.h"

/**
 * Print binary IPv4 address to a string.
 *
 * String must contain enough room for full address, 16 bytes exact.
 *
 * \param ip4addr IPv4 address.
 * \param p buffer to write string to.
 * \return length of generated string excluding the terminating null character
 */
uint_fast8_t ip4tos(const void *ip4addr, char *p);

/**
 * Convert numeric IPv4 address string to a binary.
 *
 * \param ip4addr IPv4 address in string format.
 * \param len Length of IPv4 string, maximum of 16..
 * \param dest buffer for address. MUST be 4 bytes.
 * \return boolean set to true if conversion succeed, false if it didn't
 */
bool stoip4(const char *ip4addr, size_t len, void *dest);

#ifdef __cplusplus
}
#endif
#endif
