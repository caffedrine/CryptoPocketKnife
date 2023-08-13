#ifndef ACTIHASHMAC256_H
# define ACTIHASHMAC256_H

# include "actITypes.h"
# include "actISHA2_32.h"

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C" {
# endif

/**********************************************************************************************************************
 *  actHashMACSHA256Init()
 *********************************************************************************************************************/
/*! \brief          This function initializes the HashMAC algorithm.
 *  \details        -
 *  \param[in,out]  info         (in)  pointer to context structure
 *                               (out) initialized context structure
 *  \param[in]      key          MAC key
 *  \param[in]      key_length   length of key in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_LENGTH    if key_len < 1
 *                  actOK                  else
 *  \pre            Provided pointers must be valid.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Init(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key,
   actLengthType key_length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actHashMACSHA256Update()
 *********************************************************************************************************************/
/*! \brief          This function hashes the given data and can be called arbitrarily
 *                  often between an initialize and finalize of the HashMAC algorithm.
 *                  Uses any data already in the actSHASTRUCT structure and leaves
 *                  any partial data block there.
 *  \details        -
 *  \param[in,out]  info         (in) pointer to context structure
 *                               (out) actualized context structure
 *  \param[in]      dataIN       pointer to data to be hashed
 *  \param[in]      length       length of data in bytes
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actEXCEPTION_LENGTH   total input more than 2^64 - 1 bit
 *                  actOK                 else
 *  \pre            Provided pointers must be valid.
 *                  actHashMACSHA256Init() is called once before calling this function
 *                  dataIN != NULL is a valid pointer
 *                  length >= 0
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Update(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN,
   actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 * actHashMACSHA256Finalize()
 *********************************************************************************************************************/
/*! \brief          This function finalizes the HashMAC algorithm and delivers the MAC.
 *  \details        -
 *  \param[in,out]  info         (in)  pointer to context structure
 *                               (out) finalized context structure
 *  \param[in,out]  hash         (in)  byte array to contain the hash value
 *                               (out) the final hash value (big endian of length actHASH_SIZE_SHA256)
 *  \param[in]      watchdog     pointer to watchdog reset function
 *  \return         actOK always
 *  \pre            Provided pointers must be valid.
 *                  actHashMACInit() is called once before calling this function
 *                  The buffer referenced by hash has to provide at least actHASH_SIZE_SHA256 bytes.
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actHashMACSHA256Finalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSHA256STRUCT) info,
   VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

#endif /* ACTIHASHMAC256_H */