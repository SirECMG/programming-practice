#include "stdio.h"
#include "stdlib.h"
#include <openssl/evp.h>
#include "string.h"

#include <openssl/obj_mac.h>


int main() {

    //const char *secret = "Elton\n";

    const char *secret = "abc";

    OSSL_LIB_CTX *library_context;
    const char *option_properties = NULL;
    EVP_MD_CTX *digest_context = NULL;
    EVP_MD *message_digest = NULL;

    int sz;
    unsigned int digest_length;
    unsigned char *digest_value = NULL;
    unsigned int j;







    /*
     *  create a library context
     * */
    library_context = OSSL_LIB_CTX_new();
    if(library_context == NULL) {
        printf("OSSL_LIB_CTX_new returned NULL\n");
        goto cleanup;
    }


    /*
     *  fetch a message digest by name.
     *  the algorithm name is case insensitive.
     *  see providers(7) for details about algorithm fetching
     * */
    message_digest = EVP_MD_fetch(library_context,
            SN_sha256, 
            option_properties);
    if(message_digest == NULL) {
        printf("EVP_MD_fetch could not find SHA2-256.\n");
    }

    /*
     *  determine the length of the fetched digest type
     * */
    sz = EVP_MD_get_size(message_digest);
    digest_length = (unsigned int) sz;

    digest_value = OPENSSL_malloc(digest_length);
    if(digest_value == NULL) {
        printf("no memory.\n");
        goto cleanup;
    }









    /*
     *  make a message digest context to hold temp state during digest creation
     * */

    digest_context = EVP_MD_CTX_new();
    if(digest_context == NULL) {
        printf("EVP_MD_CTX_new failed.\n");
        goto cleanup;
    }







    /*
     *  initialize the message digest context
     *  to use the fetched digest provider
     * */

    if(EVP_DigestInit(digest_context, message_digest) != 1) {
        printf("EVP_DigestInit failed.\n");
        goto cleanup;
    }

    /*
     *  apply digest to message
     * */

     if(EVP_DigestUpdate(digest_context, secret, strlen(secret)) != 1) {
        printf("EVP_DigestUpdate(hamlet_1) failed.\n");
        goto cleanup;
    }
   
     /*
      * finalized digest
      * */

     if(EVP_DigestFinal(digest_context, digest_value, &digest_length) != 1) {
        printf("EVP_DigestFinal() failed. \n");
        goto cleanup;
     }



     /*
      * print hash
      *
      * */

     for(j = 0; j < digest_length; j++) {
        printf("%02x", digest_value[j]);
     }
     printf("\n");

    printf("finished.\n");


cleanup:
    EVP_MD_CTX_free(digest_context);
    printf("yay\n");
    return EXIT_SUCCESS;
}


/*
 *
 *  notes/observations:
 *
 *  - there is a lot of ceremony in setup when trying to use the library.
 *  - a lot of moving parts such as contextes and libraries. it is just a rite of passage...
 *
 *  - there is a lot of new C conventions as well when looking at examples...
 *      - like using inline goto for cleanup
 *
 *
 *  - i need to understand the stages of using the library, for example if i want to double hash..
 *      - it seems i need to do the steps init,update,final per hash.
 * */
