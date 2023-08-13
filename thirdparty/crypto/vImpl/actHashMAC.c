#include "actIHashMAC.h"
#include "actUtilities.h"

/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actHashMACInit(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) key, actLengthType key_length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  /* ----- Local Variables ------------------------------------------------ */
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) sha = &info->sha; /* PRQA S 0781 */ /* MD_VSECPRIM_5.6 */
  VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha.buffer;
  actRETURNCODE retVal = actOK;
  actLengthType i;

  /* ----- Implementation ------------------------------------------------- */
  /* store key */
  if (key_length < 1u)
  {
    retVal = actEXCEPTION_LENGTH;
  }
  else if (key_length <= actHASH_BLOCK_SIZE_SHA)
  {
    /* copy key to key_buf */
    actMemCpyByteArray(info->key_buf, key, key_length); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    info->key_length = key_length;
  }
  else
  {
    /* use SHA-1(key) */
    (void)actSHAInit(sha);
    (void)actSHAUpdate(sha, key, key_length, watchdog);
    (void)actSHAFinalize(sha, info->key_buf, watchdog);
    info->key_length = actHASH_SIZE_SHA;
  }

  if (retVal == actOK)
  {
    /* ipad */
    actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    for (i = 0u; i < actHASH_BLOCK_SIZE_SHA; ++i)
    {
      tmp_block[i] ^= (actU8)(0x36u);
    }

    (void)actSHAInit(sha);
    (void)actSHAUpdate(sha, tmp_block, actHASH_BLOCK_SIZE_SHA, watchdog);
  }

  return retVal;
}


/**********************************************************************************************************************
 *  actHashMACUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actHashMACUpdate(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info,
   VSECPRIM_P2CONST_PARA(actU8) dataIN, actLengthType length,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  return actSHAUpdate(&info->sha, dataIN, length, watchdog);
}


/**********************************************************************************************************************
 *  actHashMACFinalize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(actRETURNCODE) actHashMACFinalize(
   VSECPRIM_P2VAR_PARA(actHASHMACSTRUCT) info, VSECPRIM_P2VAR_PARA(actU8) hash,
   VSECPRIM_P2FUNC(VSECPRIM_NONE, void, watchdog)(void))
{
  VSECPRIM_P2VAR_PARA(actSHASTRUCT) sha = &info->sha; /* PRQA S 0781 */ /* MD_VSECPRIM_5.6 */
  VSECPRIM_P2VAR_PARA(actU8) tmp_block = info->sha.buffer;
   actLengthType i;

  (void)actSHAFinalize(sha, hash, watchdog);

  /* opad */
  actMemCpyByteArray(tmp_block, info->key_buf, (info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
  actMemClear(&tmp_block[info->key_length], (actLengthType)(actHASH_BLOCK_SIZE_SHA - info->key_length)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
  for (i = 0u; i < actHASH_BLOCK_SIZE_SHA; ++i)
  {
    tmp_block[i] ^= (actU8)(0x5cu);
  }

  (void)actSHAInit(sha);
  (void)actSHAUpdate(sha, tmp_block, actHASH_BLOCK_SIZE_SHA, watchdog);
  (void)actSHAUpdate(sha, hash, actHASH_SIZE_SHA, watchdog);
  (void)actSHAFinalize(sha, hash, watchdog);

  return actOK;
}