#ifndef ACTPADDING_H
# define ACTPADDING_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

# include "actITypes.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  actPaddingInit
 **********************************************************************************************************************/
/*! \brief      Checks block padding parameter for validity.
 *  \details    This function checks the given padding mode for validity.
 *  \param[in]  mode  Requested block padding mode
 *  \return     actOK  Mode supported
 *              actEXCEPTION_ALGOID  Mode not supported
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 **********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actPaddingInit(actU8 mode);

/***********************************************************************************************************************
 *  actPaddingPad
 **********************************************************************************************************************/
/*! \brief      Pad a block using the requested padding mode
 *  \details    This functions applies padding to a given block with the requested padding mode.
 *  \param[in]  mode  Requested block padding mode
 *  \param[in]  buffer_size  Total size of block in bytes
 *  \param[in,out]  buffer_used  Input: Size of payload data in buffer, output: Total data size after padding
 *  \param[in,out]  buffer  Buffer to be padded
 *  \return     actOK  Padding operation successful
 *              actEXCEPTION_PADDING  Mode not supported
 *              actEXCEPTION_LENGTH  Insufficient buffer size
 *  \context       TASK
 *  \reentrant     TRUE, for different buffer
 *  \synchronous   TRUE
 *  \pre           Padding must be initialized
 *                 Pointers must be valid
 **********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actPaddingPad(actU8 mode, actLengthType buffer_size, VSECPRIM_P2VAR_PARA(actLengthType) buffer_used, VSECPRIM_P2VAR_PARA(actU8) buffer);

/***********************************************************************************************************************
 *  actPaddingUnpad
 **********************************************************************************************************************/
/*! \brief      Unpad a block using the requested padding mode
 *  \details    This function remove padding from the given block with the requested padding mode.
 *  \param[in]  mode  Requested block padding mode
 *  \param[in]  buffer_size  Total size of block in bytes
 *  \param[out] buffer_used  Size of payload data in buffer
 *  \param[in]  buffer  Buffer to be unpadded
 *  \return     actOK  Valid padding found
 *              actEXCEPTION_PADDING  Mode not supported or invalid padding
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           Padding must be initialized
 *                 Pointers must be valid
 **********************************************************************************************************************/
VSECPRIM_FUNC(actRETURNCODE) actPaddingUnpad(actU8 mode, actLengthType buffer_size, VSECPRIM_P2VAR_PARA(actLengthType) buffer_used, VSECPRIM_P2CONST_PARA(actU8) buffer);

#endif /* ACTPADDING_H */

/***********************************************************************************************************************
 *  END OF FILE: ACTPADDING.H
 **********************************************************************************************************************/
