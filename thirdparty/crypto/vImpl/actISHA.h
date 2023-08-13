#ifndef ACTISHA_H
# define ACTISHA_H

# include "actITypes.h"

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif
/**********************************************************************************************************************
 *  actSHAInit()
 *********************************************************************************************************************/
/*! \brief          Initialize SHA.
 *  \details        This function initializes the SHA-1 algorithm.
 *  \param[in,out]  info Pointer to the provided workspace.
 *  \return         actOK - Initialization performed
 *  \pre            info must be a valid workspace pointer
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHAInit(VSECPRIM_P2VAR_PARA(actSHASTRUCT) info);

/**********************************************************************************************************************
 *  actSHAUpdate()
 *********************************************************************************************************************/
/*! \brief       Update SHA.
 *  \details     This function hashes the given data and can be called arbitrarily often between an initialize and
 *               finalize of the SHA-1 algorithm. Uses any data already in the actSHASTRUCT structure and leaves
 *               any partial data block there.
 *  \param[in,out]  info  Pointer to the provided workspace.
 *  \param[in]   dataIn  Pointer to data to be hashed
 *  \param[in]   length  Length of data in bytes
 *  \param[in]   watchdog  Watchdog function pointer
 *  \return      actOK - Operation successful
 *               actEXCEPTION_LENGTH - Total input size exceeds 2^64 - 1 bit
 *  \pre         info must be a valid workspace pointer
 *               workspace must be initialized
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces.
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHAUpdate(
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSHAFinalize()
 *********************************************************************************************************************/
/*! \brief       Finalize SHA.
 *  \details     This function finalizes the SHA algorithm and delivers the hash value.
 *  \param[in,out]  info  Pointer to the provided workspace.
 *  \param[in,out]  hash  In: Byte array to contain the hash value; Out: The final hash value.
 *  \param[in]   watchdog  Watchdog function pointer
 *  \return      actOK - Operation successful
 *  \pre         info must be a valid workspace pointer
 *               workspace must be initialized
 *               hash must be at least 20 bytes
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces.
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHAFinalize(
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSHAGetDigest()
 *********************************************************************************************************************/
/*! \brief       Get Digest
 *  \details     Get the current (partial / internal) digest, WITHOUT FINALIZING the hash first.
 *  \param[in]       info  Pointer to hash context structure
 *  \param[in,out]   hash  In: Byte array to contain the digest value. Out: The current digest value.
 *  \param[in]       watchdog  Pointer to watchdog reset function
 *  \pre         info must be a valid workspace pointer
 *               workspace must be initialized
 *               hash must be at least 20 bytes
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces.
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(void) actSHAGetDigest(
  VSECPRIM_P2CONST_PARA(actSHASTRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
} /* extern "C" */
# endif

#endif