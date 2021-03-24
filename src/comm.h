//---------------------------------------------
// ##
// ## @Author: Med
// ## @Editor: Emacs - ggtags
// ## @TAGS:   Global
// ##
// #### COMM.H #################################
//---------------------------------------------

// Prevent recursive inclusion -------------------------------------------------
#ifndef _COMM_H_
#define _COMM_H_


// Module Exported Types Constants and Macros ----------------------------------


// Module Exported Functions ---------------------------------------------------
void UpdateCommunications (void);
void CommFlushAck (void);
unsigned char CommCheckOK (void);
unsigned char CommCheckNOK (void);


#endif    /* _COMM_H_ */

//--- end of file ---//
