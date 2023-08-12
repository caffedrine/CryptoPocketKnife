#ifndef ACTIGHASH_H
# define ACTIGHASH_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "actConfig.h"
# include "actITypes.h"
# include "actIAES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* the polynomial is 1+a+a^2+a^7+a^128 => 111000010...01 in little endian representation. */
# define GF128POLY                                                    (0xE1000000u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

/**********************************************************************************************************************
 *  actGHashReset()
 *********************************************************************************************************************/
/*! \brief          Resets the hash-block Y to zero.
 *  \details        This function resets the hash-block Y to zero.
 *                  It does NOT import the hash-subkey.
 *  \param[in,out]  info  (in)  pointer to context structure
 *                        (out) initialized context structure
 *  \return         actOK always
 *  \pre            info must be a valid workspace pointer
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
  VSECPRIM_FUNC(actRETURNCODE) actGHashReset(VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info);

/**********************************************************************************************************************
 *  actGHashInit()
 *********************************************************************************************************************/
/*! \brief          Initializes the hash-block Y to zero.
 *  \details        This function initializes the hash-block Y to zero.
 *  \param[in,out]  info  (in)  pointer to context structure
 *                        (out) initialized context structure
 *  \param[in]      H  the hash subkey
 *  \param[in]      watchdog  pointer to watchdog reset function
 *  \return         actOK always
 *  \pre            info must be a valid workspace pointer
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actGHashInit (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) H,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actGHashUpdate()
 *********************************************************************************************************************/
/*! \brief          Hashes the given data.
 *  \details        This function hashes the given data and can be called arbitrarily
 *                  often between an initialize and finalize of the GHash algorithm.
 *                  Incomplete blocks are padded with zeroes.
 *  \param[in,out]  info  (in)  pointer to initialized context structure
 *                        (out) the updated context structure
 *  \param[in]      X  the input string
 *  \param[in]      X_len  length of X in bytes
 *  \param[in]      watchdog  pointer to watchdog reset function
 *  \return         actOK always
 *  \pre            info must be a valid workspace pointer
 *                  actGHashInit() is called once before calling this function
 *                  X != NULL is a valid pointer
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actGHashUpdate (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) X,
   actLengthType X_len,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actGHashZeroPad()
 *********************************************************************************************************************/
/*! \brief          Pads abuffer with zeroes and hashes it.
 *  \details        If there is input left in the buffer, this function pads it with
 *                  zeroes and hashes it, otherwise the hash doesn't need to be padded.
 *  \param[in,out]  info  (in)  pointer to initialized context structure
 *                        (out) the updated context structure
 *  \param[in]      watchdog  pointer to watchdog reset function
 *  \return         actOK always
 *  \pre            info must be a valid workspace pointer
 *                  actGHashInit() is called once before calling this function
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actGHashZeroPad (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

/**********************************************************************************************************************
 *  actGHashFinalize()
 *********************************************************************************************************************/
/*! \brief          Finalizes the GHash algorithm and outputs the hash value.
 *  \details        This function finalizes the GHash algorithm and outputs the hash value.
 *                  Incomplete blocks are padded with zeroes.
 *  \param[in,out]  info  (in)  pointer to initialized context structure
 *                        (out) the updated context structure
 *  \param[out]     hash  byte array to contain the final hash value
 *  \param[in]      watchdog  pointer to watchdog reset function
 *  \return         actOK always
 *  \pre            info must be a valid workspace pointer
 *                  actGHashInit() is called once before calling this function
 *                  hash must point to a valid buffer of at least the size actGHASH_BLOCK_SIZE
 *  \context        TASK
 *  \reentrant      TRUE, for different workspaces.
 *  \synchronous    TRUE
 *********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actGHashFinalize (
   VSECPRIM_P2VAR_PARA(actGHASHSTRUCT) info,
   actU8 hash[actGHASH_BLOCK_SIZE],
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void));

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
}                               /* extern "C" */
# endif

#endif /* ACTIGHASH_H */

/**********************************************************************************************************************
 *  END OF FILE: actIGHash.h
 *********************************************************************************************************************/
