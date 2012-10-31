#include "test_dom_analyzer.h"
#include <iostream>

namespace osm_diff_analyzer_test_dom
{
  //------------------------------------------------------------------------------
  test_dom_analyzer::test_dom_analyzer(const osm_diff_analyzer_if::module_configuration * p_conf):
    m_name(p_conf->get_name()),
    m_level(0)
  {
  }

  //------------------------------------------------------------------------------
  const std::string & test_dom_analyzer::get_name(void)const
  {
    return m_name;
  }

  //------------------------------------------------------------------------------
  const std::string & test_dom_analyzer::get_input_type(void)const
  {
    return m_description.get_input_type();
  }

  //------------------------------------------------------------------------------
  const std::string & test_dom_analyzer::get_output_type(void)const
  {
    return m_description.get_output_type();
  }

  //------------------------------------------------------------------------------
  const std::string & test_dom_analyzer::get_type(void)const
  {
    return m_description.get_type();
  }

  //------------------------------------------------------------------------------
  void test_dom_analyzer::analyze(const osm_diff_analyzer_dom_if::t_dom_tree & p_node)
  {
    std::cout << "Level : " << m_level << std::endl ;
    std::string l_tab(m_level,'|');
    l_tab +="|=> ";
    std::cout << l_tab << "Element name : \"" << p_node.getName() << "\"" << std::endl ;
    int l_nb_text_field = p_node.nText();
    if(l_nb_text_field)
      {
	std::cout << l_tab << "Nb text fields : " << l_nb_text_field << std::endl ;
	for(int l_index=0;l_index<l_nb_text_field;++l_index)
	  {
	    std::cout << l_tab << "text_field[" << l_index << "] = \"" << p_node.getText(l_index) << "\"" << std::endl ;
	  }
      }
    int l_nb_attribute = p_node.nAttribute();
    if(l_nb_attribute)
      {
	for(int l_index=0;l_index<l_nb_attribute;++l_index)
	  {
	    XMLAttribute l_attribute = p_node.getAttribute(l_index);
	    std::cout << l_tab << "attribute[\"" << l_attribute.lpszName << "\"]=\"" << l_attribute.lpszValue << "\"" << std::endl ;
	  }
      }

    int l_nb_child_node = p_node.nChildNode();
    std::cout << l_tab << "Nb child node : " << l_nb_child_node << std::endl ;
    for(int l_index=0;l_index<l_nb_child_node;++l_index)
      {
	XMLNode l_node = p_node.getChildNode(l_index);
	++m_level;
	analyze(l_node);
	--m_level;
      }

  }

  test_dom_analyzer_description test_dom_analyzer::m_description;
}
//EOF
