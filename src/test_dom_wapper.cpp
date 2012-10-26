#include "test_dom_wrapper.h"
#include "test_dom_analyzer_description.h"
#include "test_dom_analyzer.h"
#include <cassert>
#include <iostream>

namespace osm_diff_analyzer_test_dom
{
  //----------------------------------------------------------------------------
  osm_diff_analyzer_if::general_analyzer_if * test_dom_wrapper::create_test_dom_analyzer(const osm_diff_analyzer_if::module_configuration * p_conf)
  {
    return new test_dom_analyzer(p_conf);
  }

  //----------------------------------------------------------------------------
  osm_diff_analyzer_if::analyzer_description_if * test_dom_wrapper::get_test_dom_description(void)
  {
    return new test_dom_analyzer_description();
  }

  //----------------------------------------------------------------------------
  const char * test_dom_wrapper::get_api_version(void)
  {
    return MODULE_LIBRARY_IF_VERSION;
  }

  //----------------------------------------------------------------------------
  uint32_t test_dom_wrapper::get_api_size(void)
  {
    return MODULE_LIBRARY_IF_API_SIZE;
  }

  //----------------------------------------------------------------------------
  void test_dom_wrapper::require_common_api(osm_diff_analyzer_if::module_library_if::t_register_function)
  {
    // Empty implementation as we don`t need common API
  }

  //----------------------------------------------------------------------------
  void test_dom_wrapper::cleanup(void)
  {
    //Nothing to clean
  }

  extern "C"
  {
    void register_module(void** p_api,uint32_t p_api_size)
    {
      assert(p_api_size == MODULE_LIBRARY_IF_API_SIZE);
      std::cout << "Registration of test_dom analyzer API " << std::endl ;
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_VERSION] = (void*)test_dom_wrapper::get_api_version;
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_SIZE] = (void*)test_dom_wrapper::get_api_size;
      p_api[osm_diff_analyzer_if::module_library_if::GET_DESCRIPTION] = (void*)test_dom_wrapper::get_test_dom_description;
      p_api[osm_diff_analyzer_if::module_library_if::CREATE_ANALYZER] = (void*)test_dom_wrapper::create_test_dom_analyzer;
      p_api[osm_diff_analyzer_if::module_library_if::REQUIRE_COMMON_API] = (void*)test_dom_wrapper::require_common_api;
      p_api[osm_diff_analyzer_if::module_library_if::CLEAN_UP] = (void*)test_dom_wrapper::cleanup;
    }
  }
}
//EOF
