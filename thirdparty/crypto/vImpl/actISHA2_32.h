#ifndef ACTISHA2_32_H
# define ACTISHA2_32_H

# include "actITypes.h"

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/**********************************************************************************************************************
 *  actSHA224Init()
 *********************************************************************************************************************/
/*! \brief       Initialize SHA-224
 *  \details     This function initializes the SHA-224 algorithm.
 *  \param[in,out]   info  Pointer to the workspace.
 *  \return      actOK - always
 *  \pre         info must be a valid pointer.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHA224Init(VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info);

/**********************************************************************************************************************
 *  actSHA256Init()
 *********************************************************************************************************************/
/*! \brief       Initialize SHA-256
 *  \details     This function initializes the SHA-256 algorithm.
 *  \param[in,out]   info  Pointer to the workspace.
 *  \return      actOK - always
 *  \pre         info must be a valid pointer.
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHA256Init(VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info);

/**********************************************************************************************************************
 *  actSHA224Update()
 *********************************************************************************************************************/
/*! \brief       Update of SHA-224 calculation.
 *  \details     This function hashes the given data and can be called arbitrarily often between an initialize and
 *               finalize of the hash algorithm. Uses any data already in the actSHAxxxSTRUCT structure and leaves
 *               any partial data block there.
 *  \param[in,out]   info  Pointer to the workspace
 *  \param[in]   dataIN  Pointer to data to be hashed
 *  \param[in]   length  Length of data in bytes
 *  \param[in]   watchdog  Pointer to the watchdog trigger function
 *  \return      actOK - OK
 *               actEXCEPTION_LENGTH - total input more than 2^64 - 1 bit
 *  \pre         actSHA224Init() has been called before calling this function
 *               dataIN != NULL is a valid pointer
 *               length >= 0
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHA224Update(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSHA256Update()
 *********************************************************************************************************************/
/*! \brief       Update of SHA-256 calculation.
 *  \details     This function hashes the given data and can be called arbitrarily often between an initialize and
 *               finalize of the hash algorithm. Uses any data already in the actSHAxxxSTRUCT structure and leaves
 *               any partial data block there.
 *  \param[in,out]   info  Pointer to the workspace
 *  \param[in]   dataIN  Pointer to data to be hashed
 *  \param[in]   length  Length of data in bytes
 *  \param[in]   watchdog  Pointer to the watchdog trigger function
 *  \return      actOK - OK
 *               actEXCEPTION_LENGTH - total input more than 2^64 - 1 bit
 *  \pre         actSHA256Init() has been called before calling this function
 *               dataIN != NULL is a valid pointer
 *               length >= 0
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHA256Update(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2CONST_PARA(actU8) dataIN,
  actLengthType length,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSHA224Finalize()
 *********************************************************************************************************************/
/*! \brief       Finalize SHA-224 calculation.
 *  \details     This function finalizes the hash algorithm and delivers the hash value.
 *  \param[in,out]   info  Pointer to workspace
 *  \param[out]      hash  Pointer where the hash shall be stored.
 *  \param[in]       watchdog     pointer to the watchdog function
 *  \return      actOK - always
 *  \pre         hash must have at least size of 28 bytes
 *               actSHA224Init() has been called before calling this function
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHA224Finalize(
  VSECPRIM_P2VAR_PARA(actSHA224STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actSHA256Finalize()
 *********************************************************************************************************************/
/*! \brief       Finalize SHA-256 calculation.
 *  \details     This function finalizes the hash algorithm and delivers the hash value.
 *  \param[in,out]  info  Pointer to workspace
 *  \param[out]     hash  Pointer where the hash shall be stored.
 *  \param[in]      watchdog     pointer to the watchdog function
 *  \return      actOK - always
 *  \pre         hash must have at least size of 32 bytes
 *               actSHA256Init() has been called before calling this function
 *  \context     TASK
 *  \reentrant   TRUE, for different workspaces
 *  \synchronous TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actSHA256Finalize(
  VSECPRIM_P2VAR_PARA(actSHA256STRUCT) info,
  VSECPRIM_P2VAR_PARA(actU8) hash,
  VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
  } /* extern "C" */
# endif

#endif /* ACTISHA2_32_H */
