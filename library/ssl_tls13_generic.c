/*
 *  TLS 1.3 functionality shared between client and server
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "common.h"

#if defined(MBEDTLS_SSL_TLS_C)

#if defined(MBEDTLS_SSL_PROTO_TLS1_3_EXPERIMENTAL)

#include "ssl_misc.h"

int mbedtls_ssl_start_handshake_msg( mbedtls_ssl_context *ssl,
                                     unsigned hs_type,
                                     unsigned char **buf,
                                     size_t *buflen )
{
    ((void) ssl);
    ((void) hs_type);
    ((void) buf);
    ((void) buflen);
    return( MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE );
}

int mbedtls_ssl_finish_handshake_msg( mbedtls_ssl_context *ssl,
                                      size_t buf_len,
                                      size_t msg_len )
{
    ((void) ssl);
    ((void) buf_len);
    ((void) msg_len);
    return( MBEDTLS_ERR_SSL_FEATURE_UNAVAILABLE );
}

void mbedtls_ssl_add_hs_hdr_to_checksum( mbedtls_ssl_context *ssl,
                                         unsigned hs_type,
                                         size_t total_hs_len )
{
    unsigned char hs_hdr[4];

    /* Build HS header for checksum update. */
    hs_hdr[0] = hs_type;
    hs_hdr[1] = (unsigned char)( total_hs_len >> 16 );
    hs_hdr[2] = (unsigned char)( total_hs_len >>  8 );
    hs_hdr[3] = (unsigned char)( total_hs_len >>  0 );

    ssl->handshake->update_checksum( ssl, hs_hdr, sizeof( hs_hdr ) );
}

#endif /* MBEDTLS_SSL_PROTO_TLS1_3_EXPERIMENTAL */

#endif /* MBEDTLS_SSL_TLS_C */
