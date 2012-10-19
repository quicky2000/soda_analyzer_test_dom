#ifndef _TEST_DOM_ANALYZER_H_
#define _TEST_DOM_ANALYZER_H_

#include "dom_analyzer_if.h"
#include "test_dom_analyzer_description.h"

namespace osm_diff_analyzer_test_dom
{
  class test_dom_analyzer: public osm_diff_analyzer_dom_if::dom_analyzer_if
  {
  public:
    test_dom_analyzer(const std::string & p_name);
    // Methods inherited from dom_analyzer_if
    void analyze(const osm_diff_analyzer_dom_if::t_dom_tree & p_tree);
    const std::string & get_name(void)const;
    const std::string & get_input_type(void)const;
    const std::string & get_output_type(void)const;
    const std::string & get_type(void)const;
   // End if methods inherited from dom_analyzer_if
  private:
    std::string m_name;
    unsigned int m_level;

    static test_dom_analyzer_description m_description;
  };
}
#endif // _TEST_DOM_ANALYZER_H_
//EOF
