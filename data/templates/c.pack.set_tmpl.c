{{#CSet}}
enum caut_status pack_{{ctName}}(struct caut_pack_iter * const _c_iter, struct {{ctName}} const * const _c_obj) {
  STATUS_CHECK(pack_{{ctdSetFlagsReprName}}(_c_iter, &_c_obj->_flags));
  
{{#ctdFields}}
{{#CNamedRef}}
  if (_c_obj->_flags & (1 << {{cnrIndex}})) {
    STATUS_CHECK(pack_{{cnrRefName}}(_c_iter, &_c_obj->{{cnrName}}));
  }
{{/CNamedRef}}
{{#CNamedEmpty}}
  if (_c_obj->_flags & (1 << {{cneIndex}})) {
    /* Nothing to pack for empty field {{cnrName}}. */
  }
{{/CNamedEmpty}}
{{/ctdFields}}
  
  return caut_status_ok;
}
{{/CSet}}
