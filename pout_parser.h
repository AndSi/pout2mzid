// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#ifndef POUT_PARSER_H
#define POUT_PARSER_H

#include "global.h"
#include "xmlio.h"
#include "percolator_out-pskel.hxx"
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
namespace poutXML {
  class probability_t_pimpl: public virtual probability_t_pskel {
    public:
    string probability_t;

    virtual void _characters (const ::xml_schema::ro_string&);
    };
//------------------------------------------------------------------------------
  class psm_ids_pimpl: public virtual psm_ids_pskel {
    public:
    PercolatorOutI* percolator;
    boost::unordered_map<PercolatorOutFeatures, string, PercolatorOutFeatures>* pout_values;
    string* peptide_q_value;
    string* peptide_pep;
    bool* peptide_decoy;

    virtual void pre(PercolatorOutI* percolator,string* peptide_q_value,string* peptide_pep,bool* peptide_decoy,
                     boost::unordered_map<PercolatorOutFeatures, string, PercolatorOutFeatures>& pout_values);
    virtual void psm_id(const ::std::string&);
    virtual void post_psm_ids();
    };
//------------------------------------------------------------------------------
  class psm_pimpl: public virtual psm_pskel {
    public:
    PercolatorOutI* percolator;
    string* probability_t;
    boost::unordered_map<PercolatorOutFeatures, string, PercolatorOutFeatures>* pout_values;
    string psmid,psmidfile;
    bool psm_decoy;

    virtual void pre(PercolatorOutI* percolator,string* probability_t,
                     boost::unordered_map<PercolatorOutFeatures, string, PercolatorOutFeatures>& pout_values);
    virtual void svm_score(double);
    virtual void q_value();
    virtual void pep();
    virtual void p_value();
    virtual void psm_id (const ::std::string&);
    virtual void decoy(bool);
    };
//------------------------------------------------------------------------------
  class peptide_pimpl: public virtual peptide_pskel {
    public:
    string* probability_t;
    string peptide_q_value;
    string peptide_pep;
    bool peptide_decoy;

    virtual void pre(string* probability_t);
    virtual void q_value();
    virtual void pep();
    virtual void decoy(bool);
    };
//------------------------------------------------------------------------------
  class aa_seq_t_pimpl: public virtual aa_seq_t_pskel,public ::xml_schema::string_pimpl {};
//------------------------------------------------------------------------------
  }

#endif // POUT_PARSER_H
