#ifndef DES_H
# define DES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*
 * Encryption/Decryption context of DES
 */
typedef struct
{
  uint32_t encrypt_subkeys[32];
  uint32_t decrypt_subkeys[32];
} gl_des_ctx;

/*
 * DES
 * ---
 */

/* Fill a DES context CTX with subkeys calculated from 64bit KEY.
 * Does not check parity bits, but simply ignore them.  Does not check
 * for weak keys. */
extern void
gl_des_setkey (gl_des_ctx *ctx, const char * key);

/* Electronic Codebook Mode DES encryption/decryption of data
 * according to 'mode'. */
extern void
gl_des_ecb_crypt (gl_des_ctx *ctx, const char * from,  char * to, int mode);

#define gl_des_ecb_encrypt(ctx, from, to)  gl_des_ecb_crypt(ctx, from, to, 0)
#define gl_des_ecb_decrypt(ctx, from, to)  gl_des_ecb_crypt(ctx, from, to, 1)

#endif /* DES_H */
