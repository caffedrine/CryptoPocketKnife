#ifndef ESLIB_RNG_H
# define ESLIB_RNG_H

# include "ESLib_t.h"
# include "ESLib_ERC.h"

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
extern "C"
{
# endif

# define ESL_MAXSIZEOF_WS_RNG                                         ESL_MAXSIZEOF_WS_FIPS186

  typedef struct
  {
    eslt_WorkSpaceHeader header;
    eslt_Byte wsRNG[ESL_MAXSIZEOF_WS_RNG];
  } eslt_WorkSpaceRNG;

# define ESL_SIZEOF_RNG_STATE                                         ESL_SIZEOF_RNGFIPS186_STATE

/**********************************************************************************************************************
 * esl_initRNG
 *********************************************************************************************************************/
/*!
 * \brief          Deprecated! Initialize FIPS186-2
 * \details        This function initializes the random number generator according to FIPS-186-2.
 * \param[in,out]  workSpace     (in) algorithm context buffer, initialized by esl_initWorkSpaceHeader(..) function
 *                               (out) initialized algorithm context structure
 * \param[in]      entropyLength The length of the given entropy used as seed for the RNG.
 * \param[in]      entropy       A pointer to the value that has to be used as seed.
 * \param[in]      savedState    A pointer to a state that has been saved after the previous
 *                 initialisation. Length is given by ESL_SIZEOF_RNGFIPS186_STATE.
 *                 If this pointer is set to NULL, no savedState is used.
 * \return         ESL_ERC_PARAMETER_INVALID input parameter is NULL
 *                 ESL_ERC_WS_TOO_SMALL      work space too small
 *                 ESL_ERC_MODE_INVALID      block or padding mode is invalid
 *                 ESL_ERC_NO_ERROR          else
 * \pre            workSpace is initialized by esl_initWorkSpaceHeader(..)
 * \context        TASK
 * \reentrant      TRUE
 * \synchronous    TRUE
 *********************************************************************************************************************/
extern VSECPRIM_FUNC(eslt_ErrorCode) esl_initRNG(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceRNG) workSpace,
  const eslt_Length entropyLength,
  VSECPRIM_P2CONST_PARA(eslt_Byte) entropy,
  VSECPRIM_P2VAR_PARA(eslt_Byte) savedState);

/**********************************************************************************************************************
 * esl_getBytesRNG
 *********************************************************************************************************************/
/*!
 * \brief          Get random byte
 * \details        This function generates random numbers according to FIPS-186-2.
 * \param[in]      targetLength    the number of bytes that shall be generated
 * \param[in,out]  target          (in) pointer to output buffer with at least targetLength bytes.
 *                                 (out) pointer to generated random bytes
 * \return         ESL_ERC_PARAMETER_INVALID input parameter is NULL
 *                 ESL_ERC_WS_STATE_INVALID  work space state invalid
 *                 ESL_ERC_WS_TOO_SMALL      work space too small
 *                 ESL_ERC_NO_ERROR          else
 * \pre            -
 * \context        TASK
 * \reentrant      TRUE
 * \synchronous    TRUE
 *********************************************************************************************************************/
extern VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesRNG(
  const eslt_Length targetLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) target);

/**********************************************************************************************************************
 * esl_stirRNG
 *********************************************************************************************************************/
/*!
 * \brief          Deprecated! Stir up seed state.
 * \details        This function stirs up the internal state of the random number generator.
 * \param[in]      inputLength   the number of input bytes used to stir up therandom number generator
 * \param[in]      input         pointer to input bytes used to stir up the random number generator
 * \return         ESL_ERC_PARAMETER_INVALID input parameter is NULL
 *                 ESL_ERC_WS_STATE_INVALID  work space state invalid
 *                 ESL_ERC_WS_TOO_SMALL      work space too small
 *                 ESL_ERC_NO_ERROR          else
 * \pre            -
 * \context        TASK
 * \reentrant      TRUE
 * \synchronous    TRUE
 *********************************************************************************************************************/
extern VSECPRIM_FUNC(eslt_ErrorCode) esl_stirRNG(
  const eslt_Length inputLength,
  VSECPRIM_P2VAR_PARA(eslt_Byte) input);

# ifdef __cplusplus                                       /* COV_VSECPRIM_CPLUSPLUS XF */
}                               /* extern "C" */
# endif

#endif /* ESLIB_RNG_H */

/**********************************************************************************************************************
 *  END OF FILE: ESLib_RNG.h
 *********************************************************************************************************************/
