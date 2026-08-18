#ifndef __DIAMETER_PEG_H__
#define __DIAMETER_PEG_H__

#include <pthread.h>
#include <atomic> 

class DiameterPeg {

	public:
		enum E_BaseAction
		{
			E_CER_MSG,
			E_CEA_SUCCESS_MSG,
			E_CEA_FAIL_MSG,

			E_DWR_MSG,
			E_DWA_SUCCESS_MSG,
			E_DWA_FAIL_MSG,

			E_DPR_MSG,
			E_DPA_SUCCESS_MSG,
			E_DPA_FAIL_MSG,

			E_RCV_MSG,
			E_SEND_MSG,

			E_SYS_ERR,

			E_NUM_OF_BASE_ACTION,

			E_ERROR_BIT,
			E_RETX_BIT
		};

		enum E_DccaAction
		{
			E_CCR_INITIAL_MSG,
			E_CCR_INITIAL_DROP_MSG,
			E_CCR_INITIAL_TIMEOUT_MSG,
			E_CCA_INITIAL_SUCCESS_MSG,
			E_CCA_INITIAL_FAIL_MSG,

			E_CCR_UPDATE_MSG,
			E_CCR_UPDATE_DROP_MSG,
			E_CCR_UPDATE_TIMEOUT_MSG,
			E_CCA_UPDATE_SUCCESS_MSG,
			E_CCA_UPDATE_FAIL_MSG,

			E_CCR_TERMINATE_MSG,
			E_CCR_TERMINATE_DROP_MSG,
			E_CCR_TERMINATE_TIMEOUT_MSG,
			E_CCA_TERMINATE_SUCCESS_MSG,
			E_CCA_TERMINATE_FAIL_MSG,

			E_RAR_MSG,
			E_RAR_DROP_MSG,
			E_RAR_TIMEOUT_MSG,
			E_RAA_SUCCESS_MSG,
			E_RAA_FAIL_MSG,

			E_ASR_MSG,
			E_ASR_DROP_MSG,
			E_ASR_TIMEOUT_MSG,
			E_ASA_SUCCESS_MSG,
			E_ASA_FAIL_MSG,

			E_STR_MSG,
			E_STR_DROP_MSG,
			E_STR_TIMEOUT_MSG,
			E_STA_SUCCESS_MSG,
			E_STA_FAIL_MSG,

			E_SY_STR_MSG,
			E_SY_STR_DROP_MSG,
			E_SY_STR_TIMEOUT_MSG,
			E_SY_STA_SUCCESS_MSG,
			E_SY_STA_FAIL_MSG,
			
			E_SY_SLR_MSG,
			E_SY_SLR_DROP_MSG,
			E_SY_SLR_TIMEOUT_MSG,
			E_SY_SLA_SUCCESS_MSG,
			E_SY_SLA_FAIL_MSG,
		
         E_SY_SLR_INTER_MSG,
         E_SY_SLR_INTER_DROP_MSG,
         E_SY_SLR_INTER_TIMEOUT_MSG,
         E_SY_SLA_INTER_SUCCESS_MSG,
         E_SY_SLA_INTER_FAIL_MSG,

			E_SY_SNR_MSG,
			E_SY_SNR_DROP_MSG,
			E_SY_SNR_TIMEOUT_MSG,
			E_SY_SNA_SUCCESS_MSG,
			E_SY_SNA_FAIL_MSG,
			
         E_AAR_MSG,
			E_AAR_DROP_MSG,
			E_AAR_TIMEOUT_MSG,
			E_AAA_SUCCESS_MSG,
			E_AAA_FAIL_MSG,

         E_ULR_MSG,
			E_ULR_DROP_MSG,
			E_ULR_TIMEOUT_MSG,
			E_ULA_SUCCESS_MSG,
			E_ULA_FAIL_MSG,

			E_S6A_ULR_MSG,
			E_S6A_AIR_MSG,
			E_S6A_AIR_DROP_MSG,
			E_S6A_AIR_TIMEOUT_MSG,
			E_S6A_AIA_SUCCESS_MSG,
			E_S6A_AIA_FAIL_MSG,

			E_S6A_PUR_MSG,
			E_S6A_PUR_DROP_MSG,
			E_S6A_PUR_TIMEOUT_MSG,
			E_S6A_PUA_SUCCESS_MSG,
			E_S6A_PUA_FAIL_MSG,

			E_S6A_CLR_MSG,
			E_S6A_CLR_DROP_MSG,
			E_S6A_CLR_TIMEOUT_MSG,
			E_S6A_CLA_SUCCESS_MSG,
			E_S6A_CLA_FAIL_MSG,

			E_S6A_IDR_MSG,
			E_S6A_IDR_DROP_MSG,
			E_S6A_IDR_TIMEOUT_MSG,
			E_S6A_IDA_SUCCESS_MSG,
			E_S6A_IDA_FAIL_MSG,

			E_S6A_DSR_MSG,
			E_S6A_DSR_DROP_MSG,
			E_S6A_DSR_TIMEOUT_MSG,
			E_S6A_DSA_SUCCESS_MSG,
			E_S6A_DSA_FAIL_MSG,

			E_S6A_RSR_MSG,
			E_S6A_RSR_DROP_MSG,
			E_S6A_RSR_TIMEOUT_MSG,
			E_S6A_RSA_SUCCESS_MSG,
			E_S6A_RSA_FAIL_MSG,

			E_S6A_NOR_MSG,
			E_S6A_NOR_DROP_MSG,
			E_S6A_NOR_TIMEOUT_MSG,
			E_S6A_NOA_SUCCESS_MSG,
			E_S6A_NOA_FAIL_MSG,

			E_SLH_RIR_MSG,
                        E_SLH_RIR_DROP_MSG,
                        E_SLH_RIR_TIMEOUT_MSG,
                        E_SLH_RIA_SUCCESS_MSG,
                        E_SLH_RIA_FAIL_MSG,

		      E_SD_TSR_MSG,
		      E_SD_TSR_DROP_MSG,
		      E_SD_TSR_TIMEOUT_MSG,
		      E_SD_TSA_SUCCESS_MSG,
		      E_SD_TSA_FAIL_MSG,

		      E_SD_CCR_MSG,
		      E_SD_CCR_DROP_MSG,
		      E_SD_CCR_TIMEOUT_MSG,
		      E_SD_CCA_SUCCESS_MSG,
		      E_SD_CCA_FAIL_MSG,

		      E_SD_RAR_MSG,
		      E_SD_RAR_DROP_MSG,
		      E_SD_RAR_TIMEOUT_MSG,
		      E_SD_RAA_SUCCESS_MSG,
		      E_SD_RAA_FAIL_MSG,


		      E_SH_UDR_MSG,
		      E_SH_UDR_DROP_MSG,
		      E_SH_UDR_TIMEOUT_MSG,
		      E_SH_UDA_SUCCESS_MSG,
		      E_SH_UDA_FAIL_MSG,

		      E_SH_PUR_MSG,
		      E_SH_PUR_DROP_MSG,
		      E_SH_PUR_TIMEOUT_MSG,
		      E_SH_PUA_SUCCESS_MSG,
		      E_SH_PUA_FAIL_MSG,

		      E_SH_SNR_MSG,
		      E_SH_SNR_DROP_MSG,
		      E_SH_SNR_TIMEOUT_MSG,
		      E_SH_SNA_SUCCESS_MSG,
		      E_SH_SNA_FAIL_MSG,

		      E_SH_PNR_MSG,
		      E_SH_PNR_DROP_MSG,
		      E_SH_PNR_TIMEOUT_MSG,
		      E_SH_PNA_SUCCESS_MSG,
		      E_SH_PNA_FAIL_MSG,


		      E_CX_UAR_MSG,
		      E_CX_UAR_DROP_MSG,
		      E_CX_UAR_TIMEOUT_MSG,
		      E_CX_UAA_SUCCESS_MSG,
		      E_CX_UAA_FAIL_MSG,

		      E_CX_SAR_MSG,
		      E_CX_SAR_DROP_MSG,
		      E_CX_SAR_TIMEOUT_MSG,
		      E_CX_SAA_SUCCESS_MSG,
		      E_CX_SAA_FAIL_MSG,

		      E_CX_LIR_MSG,
		      E_CX_LIR_DROP_MSG,
		      E_CX_LIR_TIMEOUT_MSG,
		      E_CX_LIA_SUCCESS_MSG,
		      E_CX_LIA_FAIL_MSG,

		      E_CX_MAR_MSG,
		      E_CX_MAR_DROP_MSG,
		      E_CX_MAR_TIMEOUT_MSG,
		      E_CX_MAA_SUCCESS_MSG,
		      E_CX_MAA_FAIL_MSG,

		      E_CX_RTR_MSG,
		      E_CX_RTR_DROP_MSG,
		      E_CX_RTR_TIMEOUT_MSG,
		      E_CX_RTA_SUCCESS_MSG,
		      E_CX_RTA_FAIL_MSG,

		      E_CX_PPR_MSG,
		      E_CX_PPR_DROP_MSG,
		      E_CX_PPR_TIMEOUT_MSG,
		      E_CX_PPA_SUCCESS_MSG,
		      E_CX_PPA_FAIL_MSG,

			E_CC_EVENT_MSG,
			E_CC_EVENT_DROP_MSG,
			E_CC_EVENT_TIMEOUT_MSG,
			E_CC_EVENT_SUCCESS_MSG,
			E_CC_EVENT_FAIL_MSG,

			E_UNEXPECTED_MSG,

			E_NUM_OF_DCCA_ACTION
		};

		DiameterPeg();
		~DiameterPeg();

		//static DiameterPeg* createInstance();

		void GeneratePeg(E_BaseAction action);

		void GeneratePeg(E_DccaAction action);
		
		void ClearPeg();

		void CummulateCount();

		unsigned m_cer;
		unsigned m_cea_success;
		unsigned m_cea_fail;

		unsigned m_dwr;
		unsigned m_dwa_success;
		unsigned m_dwa_fail;

		unsigned m_dpr;
		unsigned m_dpa_success;
		unsigned m_dpa_fail;

		unsigned m_rcv;
		unsigned m_send;

		unsigned m_ccr_initial;
		unsigned m_ccr_initial_drop;
		unsigned m_ccr_initial_timeout;
		unsigned m_cca_initial_success;
		unsigned m_cca_initial_fail;

		unsigned m_ccr_update;
		unsigned m_ccr_update_drop;
		unsigned m_ccr_update_timeout;
		unsigned m_cca_update_success;
		unsigned m_cca_update_fail;

		unsigned m_ccr_terminate;
		unsigned m_ccr_terminate_drop;
		unsigned m_ccr_terminate_timeout;
		unsigned m_cca_terminate_success;
		unsigned m_cca_terminate_fail;

		unsigned m_rar;
		unsigned m_rar_drop;
		unsigned m_rar_timeout;
		unsigned m_raa_success;
		unsigned m_raa_fail;

		unsigned m_asr;
		unsigned m_asr_drop;
		unsigned m_asr_timeout;
		unsigned m_asa_success;
		unsigned m_asa_fail;

		unsigned m_aar;
		unsigned m_aar_drop;
		unsigned m_aar_timeout;
		unsigned m_aaa_success;
		unsigned m_aaa_fail;
		
      unsigned m_str;
		unsigned m_str_drop;
		unsigned m_str_timeout;
		unsigned m_sta_success;
		unsigned m_sta_fail;

      unsigned m_slr;
      unsigned m_slr_drop;
      unsigned m_slr_timeout;
      unsigned m_sla_success;
      unsigned m_sla_fail;

      unsigned m_slr_interm;
      unsigned m_slr_interm_drop;
      unsigned m_slr_interm_timeout;
      unsigned m_sla_interm_success;
      unsigned m_sla_interm_fail;

		unsigned m_snr;
		unsigned m_snr_drop;
		unsigned m_snr_timeout;
		unsigned m_sna_success;
		unsigned m_sna_fail;

		unsigned m_str_sy;
		unsigned m_str_drop_sy;
		unsigned m_str_timeout_sy;
		unsigned m_sta_success_sy;
		unsigned m_sta_fail_sy;
		
    unsigned m_ulr;           // Update-Location-Request
    unsigned m_ulr_drop;      // Update-Location-Request Drop
    unsigned m_ulr_timeout;   // Update-Location-Request Timeout
    unsigned m_ula_success;   // Update-Location-Answer Success
    unsigned m_ula_fail;      // Update-Location-Answer Failure
    
    unsigned m_air;           // Authentication-Information-Request
    unsigned m_air_drop;      // Authentication-Information-Request Drop
    unsigned m_air_timeout;   // Authentication-Information-Request Timeout
    unsigned m_aia_success;   // Authentication-Information-Answer Success
    unsigned m_aia_fail;      // Authentication-Information-Answer Failure
    
    unsigned m_pur;           // Purge-UE-Request
    unsigned m_pur_drop;      // Purge-UE-Request Drop
    unsigned m_pur_timeout;   // Purge-UE-Request Timeout
    unsigned m_pua_success;   // Purge-UE-Answer Success
    unsigned m_pua_fail;      // Purge-UE-Answer Failure
    
    unsigned m_clr;           // Cancel-Location-Request
    unsigned m_clr_drop;      // Cancel-Location-Request Drop
    unsigned m_clr_timeout;   // Cancel-Location-Request Timeout
    unsigned m_cla_success;   // Cancel-Location-Answer Success
    unsigned m_cla_fail;      // Cancel-Location-Answer Failure
    
    unsigned m_idr;           // Insert-Subscriber-Data-Request
    unsigned m_idr_drop;      // Insert-Subscriber-Data-Request Drop
    unsigned m_idr_timeout;   // Insert-Subscriber-Data-Request Timeout
    unsigned m_ida_success;   // Insert-Subscriber-Data-Answer Success
    unsigned m_ida_fail;      // Insert-Subscriber-Data-Answer Failure
    
    unsigned m_dsr;           // Delete-Subscriber-Data-Request
    unsigned m_dsr_drop;      // Delete-Subscriber-Data-Request Drop
    unsigned m_dsr_timeout;   // Delete-Subscriber-Data-Request Timeout
    unsigned m_dsa_success;   // Delete-Subscriber-Data-Answer Success
    unsigned m_dsa_fail;      // Delete-Subscriber-Data-Answer Failure
    
    unsigned m_rsr;           // Reset-Request
    unsigned m_rsr_drop;      // Reset-Request Drop
    unsigned m_rsr_timeout;   // Reset-Request Timeout
    unsigned m_rsa_success;   // Reset-Answer Success
    unsigned m_rsa_fail;      // Reset-Answer Failure
    
    unsigned m_nor;           // Notify-Request
    unsigned m_nor_drop;      // Notify-Request Drop
    unsigned m_nor_timeout;   // Notify-Request Timeout
    unsigned m_noa_success;   // Notify-Answer Success
    unsigned m_noa_fail;      // Notify-Answer Failure	
          
    
  unsigned m_rir;           
  unsigned m_rir_drop;      
  unsigned m_rir_timeout;   
  unsigned m_ria_success;   
  unsigned m_ria_fail;      
    
  unsigned m_sd_tsr;
    unsigned m_sd_tsr_drop;
    unsigned m_sd_tsr_timeout;
    unsigned m_sd_tsa_success;
    unsigned m_sd_tsa_fail;

    unsigned m_sd_ccr;
    unsigned m_sd_ccr_drop;
    unsigned m_sd_ccr_timeout;
    unsigned m_sd_cca_success;
    unsigned m_sd_cca_fail;

    unsigned m_sd_rar;
    unsigned m_sd_rar_drop;
    unsigned m_sd_rar_timeout;
    unsigned m_sd_raa_success;
    unsigned m_sd_raa_fail;
    
    unsigned m_sh_udr;
    unsigned m_sh_udr_drop;
    unsigned m_sh_udr_timeout;
    unsigned m_sh_uda_success;
    unsigned m_sh_uda_fail;

    unsigned m_sh_pur;
    unsigned m_sh_pur_drop;
    unsigned m_sh_pur_timeout;
    unsigned m_sh_pua_success;
    unsigned m_sh_pua_fail;

    unsigned m_sh_snr;
    unsigned m_sh_snr_drop;
    unsigned m_sh_snr_timeout;
    unsigned m_sh_sna_success;
    unsigned m_sh_sna_fail;

    unsigned m_sh_pnr;
    unsigned m_sh_pnr_drop;
    unsigned m_sh_pnr_timeout;
    unsigned m_sh_pna_success;
    unsigned m_sh_pna_fail;    


    unsigned m_cx_uar;
    unsigned m_cx_uar_drop;
    unsigned m_cx_uar_timeout;
    unsigned m_cx_uaa_success;
    unsigned m_cx_uaa_fail;

    unsigned m_cx_sar;
    unsigned m_cx_sar_drop;
    unsigned m_cx_sar_timeout;
    unsigned m_cx_saa_success;
    unsigned m_cx_saa_fail;

    unsigned m_cx_lir;
    unsigned m_cx_lir_drop;
    unsigned m_cx_lir_timeout;
    unsigned m_cx_lia_success;
    unsigned m_cx_lia_fail;

    unsigned m_cx_mar;
    unsigned m_cx_mar_drop;
    unsigned m_cx_mar_timeout;
    unsigned m_cx_maa_success;
    unsigned m_cx_maa_fail;

    unsigned m_cx_rtr;
    unsigned m_cx_rtr_drop;
    unsigned m_cx_rtr_timeout;
    unsigned m_cx_rta_success;
    unsigned m_cx_rta_fail;

    unsigned m_cx_ppr;
    unsigned m_cx_ppr_drop;
    unsigned m_cx_ppr_timeout;
    unsigned m_cx_ppa_success;
    unsigned m_cx_ppa_fail;

    unsigned m_unexpected;



		unsigned m_sytem_error;

		unsigned m_error_bit;
		unsigned m_retx_bit;

		std::atomic<unsigned long>      m_cummulatedReq;
		std::atomic<unsigned long>      m_cummulatedAns;
		//unsigned long m_cummulatedReq;
		//unsigned long m_cummulatedAns;

	private:
		//static DiameterPeg*    m_instance;
		pthread_spinlock_t m_base_spinlock[E_NUM_OF_BASE_ACTION];
		pthread_spinlock_t m_dcca_spinlock[E_NUM_OF_DCCA_ACTION];

		pthread_mutex_t m_clear_mutex;
		pthread_mutex_t m_cummulation_mutex;
		//pthread_mutex_t m_base_mutex[E_NUM_OF_BASE_ACTION];
		//pthread_mutex_t m_dcca_mutex[E_NUM_OF_DCCA_ACTION];

};

#endif
