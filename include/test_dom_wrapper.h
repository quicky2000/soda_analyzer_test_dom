#ifndef _TEST_DOM_WRAPPER_H_
#define _TEST_DOM_WRAPPER_H_

#include "general_analyzer_if.h"
#include "module_library_if.h"

#include <stdint.h>
namespace osm_diff_analyzer_test_dom
{
  class test_dom_wrapper
  {
  public:
    static const char * get_api_version(void);
    static uint32_t get_api_size(void);
    static osm_diff_analyzer_if::general_analyzer_if * create_test_dom_analyzer(const std::string & p_name);
    static osm_diff_analyzer_if::analyzer_description_if * get_test_dom_description(void);
    static void require_common_api(osm_diff_analyzer_if::module_library_if::t_register_function);
    static void cleanup(void);
  private:
  };

}
#endif // _TEST_DOM_WRAPPER_H_
//EOF
