/*
 * INTERRUPT_test.c
 *
 * Created:
 *  Author: ammar
 */ 

EN_EXINT_Error_t EXINT_Test() {
	u8 LocError;
	
	LocError = EXINT_EnableGlobalInterrupts();
	ERROR_CHECK_RETURN(LocError);
	
	LocError = EXINT_DisableGlobalInterrupts();
	ERROR_CHECK_RETURN(LocError);
	
	LocError = EXINT_InitInterrupt(EXINT0);
	ERROR_CHECK_RETURN(LocError);
	
	return EXINT_OK;
}