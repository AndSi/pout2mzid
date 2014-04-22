// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//
//------------------------------------------------------------------------------
#include <iostream>
#include "pout_parser.h"
//------------------------------------------------------------------------------
namespace poutXML {
  void probability_t_pimpl::_characters(const ::xml_schema::ro_string& s) {
    probability_t=s;
    }
//------------------------------------------------------------------------------
  void psm_ids_pimpl::pre(PercolatorOutI* percolator,string* peptide_q_value,string* peptide_pep,bool* peptide_decoy,
                          boost::unordered_map<PercolatorOutFeatures, string, PercolatorOutFeatures>& pout_values) {
    this->percolator=percolator;
    this->peptide_q_value=peptide_q_value;
    *this->peptide_q_value="";
    this->peptide_pep=peptide_pep;
    *this->peptide_pep="";
    this->peptide_decoy=peptide_decoy;
    this->pout_values=&pout_values;
    }
//------------------------------------------------------------------------------
  void psm_ids_pimpl::post_psm_ids() {
    *peptide_pep="";
    *peptide_q_value="";
    }
//------------------------------------------------------------------------------
  void psm_ids_pimpl::psm_id(const ::std::string& psm_id) {
    string psmid,psmidfile;

    if (!percolator->checkDecoy(*peptide_decoy))
      return;
    psmid=percolator->convertPSMID(psm_id);
    if (psmid.length()==0)
      THROW_ERROR_VALUE(PRINT_TEXT::WRONG_FORMAT_PSM,psm_id);
    psmidfile=percolator->convertPSMIDFileName(psm_id);
    if (psmidfile.length()==0)
      THROW_ERROR_VALUE(PRINT_TEXT::NO_UNIQUE_MZID_FILE,psm_id);
    if (peptide_pep->length()>0)
      (*pout_values)[PercolatorOutFeatures(psmidfile,psmid,PERCOLATOR_PARAM::PEPTIDE_PEP)]=*peptide_pep;
    if (peptide_q_value->length()>0)
      (*pout_values)[PercolatorOutFeatures(psmidfile,psmid,PERCOLATOR_PARAM::PEPTIDE_Q_VALUE)]=*peptide_q_value;
    }
//------------------------------------------------------------------------------
  void psm_pimpl::pre(PercolatorOutI* percolator,string* probability_t,
                      boost::unordered_map<PercolatorOutFeatures, string, PercolatorOutFeatures>& pout_values) {
    this->percolator=percolator;
    this->probability_t=probability_t;
    this->pout_values=&pout_values;
    }
//------------------------------------------------------------------------------
  void psm_pimpl::svm_score(double svm_score) {
    if (psm_decoy)
      (*pout_values)[PercolatorOutFeatures(psmidfile,psmid,PERCOLATOR_PARAM::SVM_SCORE)]=global::to_string(svm_score);
    }
//------------------------------------------------------------------------------
  void psm_pimpl::q_value() {
    if (psm_decoy)
      (*pout_values)[PercolatorOutFeatures(psmidfile,psmid,PERCOLATOR_PARAM::Q_VALUE)]=global::to_string(*probability_t);
    }
//------------------------------------------------------------------------------
  void psm_pimpl::pep() {
    if (psm_decoy)
      (*pout_values)[PercolatorOutFeatures(psmidfile,psmid,PERCOLATOR_PARAM::PEP)]=global::to_string(*probability_t);
    }
//------------------------------------------------------------------------------
  void psm_pimpl::p_value() {
    if (psm_decoy)
      (*pout_values)[PercolatorOutFeatures(psmidfile,psmid,PERCOLATOR_PARAM::P_VALUE)]=global::to_string(*probability_t);
    }
//------------------------------------------------------------------------------
  void psm_pimpl::psm_id(const ::std::string& psm_id) {
    psmid=percolator->convertPSMID(psm_id);
    if (psmid.length()==0)
      THROW_ERROR_VALUE(PRINT_TEXT::WRONG_FORMAT_PSM,psm_id);
    psmidfile=percolator->convertPSMIDFileName(psm_id);
    if (psmidfile.length()==0)
      THROW_ERROR_VALUE(PRINT_TEXT::NO_UNIQUE_MZID_FILE,psm_id);
    }
//------------------------------------------------------------------------------
  void psm_pimpl::decoy(bool decoy) {
    psm_decoy=percolator->checkDecoy(decoy);
    }
//------------------------------------------------------------------------------
  void peptide_pimpl::pre(string* probability_t) {
    this->probability_t=probability_t;
    }
//------------------------------------------------------------------------------
  void peptide_pimpl::q_value() {
    peptide_q_value=*probability_t;
    }
//------------------------------------------------------------------------------
  void peptide_pimpl::pep() {
    peptide_pep=*probability_t;
    }
//------------------------------------------------------------------------------
  void peptide_pimpl::decoy(bool decoy) {
    peptide_decoy=decoy;
    }
//------------------------------------------------------------------------------
  }