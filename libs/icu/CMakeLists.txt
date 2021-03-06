cmake_minimum_required(VERSION 3.22)
project(icuuc)

# https://unicode-org.github.io/icu/userguide/icu/howtouseicu.html#c-with-your-own-build-system

set(ICU_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/icu/icu4c/source)
set(INCLUDE_DIR ${ICU_SRC_DIR}/common)

set(ICU_INCLUDE_DIR ${INCLUDE_DIR} PARENT_SCOPE)
set(ICU_LIBRARY ${PROJECT_NAME} PARENT_SCOPE)

add_library(${PROJECT_NAME}
    # icuuc
    ${ICU_SRC_DIR}/common/appendable.cpp
    ${ICU_SRC_DIR}/common/bmpset.cpp
    ${ICU_SRC_DIR}/common/brkeng.cpp
    ${ICU_SRC_DIR}/common/brkiter.cpp
    ${ICU_SRC_DIR}/common/bytesinkutil.cpp
    ${ICU_SRC_DIR}/common/bytestream.cpp
    ${ICU_SRC_DIR}/common/bytestrie.cpp
    ${ICU_SRC_DIR}/common/bytestriebuilder.cpp
    ${ICU_SRC_DIR}/common/bytestrieiterator.cpp
    ${ICU_SRC_DIR}/common/caniter.cpp
    ${ICU_SRC_DIR}/common/characterproperties.cpp
    ${ICU_SRC_DIR}/common/chariter.cpp
    ${ICU_SRC_DIR}/common/charstr.cpp
    ${ICU_SRC_DIR}/common/cmemory.cpp
    ${ICU_SRC_DIR}/common/cstr.cpp
    ${ICU_SRC_DIR}/common/cstring.cpp
    ${ICU_SRC_DIR}/common/cwchar.cpp
    ${ICU_SRC_DIR}/common/dictbe.cpp
    ${ICU_SRC_DIR}/common/dictionarydata.cpp
    ${ICU_SRC_DIR}/common/dtintrv.cpp
    ${ICU_SRC_DIR}/common/edits.cpp
    ${ICU_SRC_DIR}/common/emojiprops.cpp
    ${ICU_SRC_DIR}/common/errorcode.cpp
    ${ICU_SRC_DIR}/common/filteredbrk.cpp
    ${ICU_SRC_DIR}/common/filterednormalizer2.cpp
    ${ICU_SRC_DIR}/common/icudataver.cpp
    ${ICU_SRC_DIR}/common/icuplug.cpp
    ${ICU_SRC_DIR}/common/loadednormalizer2impl.cpp
    ${ICU_SRC_DIR}/common/localebuilder.cpp
    ${ICU_SRC_DIR}/common/localematcher.cpp
    ${ICU_SRC_DIR}/common/localeprioritylist.cpp
    ${ICU_SRC_DIR}/common/locavailable.cpp
    ${ICU_SRC_DIR}/common/locbased.cpp
    ${ICU_SRC_DIR}/common/locdispnames.cpp
    ${ICU_SRC_DIR}/common/locdistance.cpp
    ${ICU_SRC_DIR}/common/locdspnm.cpp
    ${ICU_SRC_DIR}/common/locid.cpp
    ${ICU_SRC_DIR}/common/loclikely.cpp
    ${ICU_SRC_DIR}/common/loclikelysubtags.cpp
    ${ICU_SRC_DIR}/common/locmap.cpp
    ${ICU_SRC_DIR}/common/locresdata.cpp
    ${ICU_SRC_DIR}/common/locutil.cpp
    ${ICU_SRC_DIR}/common/lsr.cpp
    ${ICU_SRC_DIR}/common/lstmbe.cpp
    ${ICU_SRC_DIR}/common/messagepattern.cpp
    ${ICU_SRC_DIR}/common/normalizer2.cpp
    ${ICU_SRC_DIR}/common/normalizer2impl.cpp
    ${ICU_SRC_DIR}/common/normlzr.cpp
    ${ICU_SRC_DIR}/common/parsepos.cpp
    ${ICU_SRC_DIR}/common/patternprops.cpp
    ${ICU_SRC_DIR}/common/pluralmap.cpp
    ${ICU_SRC_DIR}/common/propname.cpp
    ${ICU_SRC_DIR}/common/propsvec.cpp
    ${ICU_SRC_DIR}/common/punycode.cpp
    ${ICU_SRC_DIR}/common/putil.cpp
    ${ICU_SRC_DIR}/common/rbbi.cpp
    ${ICU_SRC_DIR}/common/rbbi_cache.cpp
    ${ICU_SRC_DIR}/common/rbbidata.cpp
    ${ICU_SRC_DIR}/common/rbbinode.cpp
    ${ICU_SRC_DIR}/common/rbbirb.cpp
    ${ICU_SRC_DIR}/common/rbbiscan.cpp
    ${ICU_SRC_DIR}/common/rbbisetb.cpp
    ${ICU_SRC_DIR}/common/rbbistbl.cpp
    ${ICU_SRC_DIR}/common/rbbitblb.cpp
    ${ICU_SRC_DIR}/common/resbund.cpp
    ${ICU_SRC_DIR}/common/resbund_cnv.cpp
    ${ICU_SRC_DIR}/common/resource.cpp
    ${ICU_SRC_DIR}/common/restrace.cpp
    ${ICU_SRC_DIR}/common/ruleiter.cpp
    ${ICU_SRC_DIR}/common/schriter.cpp
    ${ICU_SRC_DIR}/common/serv.cpp
    ${ICU_SRC_DIR}/common/servlk.cpp
    ${ICU_SRC_DIR}/common/servlkf.cpp
    ${ICU_SRC_DIR}/common/servls.cpp
    ${ICU_SRC_DIR}/common/servnotf.cpp
    ${ICU_SRC_DIR}/common/servrbf.cpp
    ${ICU_SRC_DIR}/common/servslkf.cpp
    ${ICU_SRC_DIR}/common/sharedobject.cpp
    ${ICU_SRC_DIR}/common/simpleformatter.cpp
    ${ICU_SRC_DIR}/common/static_unicode_sets.cpp
    ${ICU_SRC_DIR}/common/stringpiece.cpp
    ${ICU_SRC_DIR}/common/stringtriebuilder.cpp
    ${ICU_SRC_DIR}/common/uarrsort.cpp
    ${ICU_SRC_DIR}/common/ubidi.cpp
    ${ICU_SRC_DIR}/common/ubidi_props.cpp
    ${ICU_SRC_DIR}/common/ubidiln.cpp
    ${ICU_SRC_DIR}/common/ubiditransform.cpp
    ${ICU_SRC_DIR}/common/ubidiwrt.cpp
    ${ICU_SRC_DIR}/common/ubrk.cpp
    ${ICU_SRC_DIR}/common/ucase.cpp
    ${ICU_SRC_DIR}/common/ucasemap.cpp
    ${ICU_SRC_DIR}/common/ucasemap_titlecase_brkiter.cpp
    ${ICU_SRC_DIR}/common/ucat.cpp
    ${ICU_SRC_DIR}/common/uchar.cpp
    ${ICU_SRC_DIR}/common/ucharstrie.cpp
    ${ICU_SRC_DIR}/common/ucharstriebuilder.cpp
    ${ICU_SRC_DIR}/common/ucharstrieiterator.cpp
    ${ICU_SRC_DIR}/common/uchriter.cpp
    ${ICU_SRC_DIR}/common/ucln_cmn.cpp
    ${ICU_SRC_DIR}/common/ucmndata.cpp
    ${ICU_SRC_DIR}/common/ucnv.cpp
    ${ICU_SRC_DIR}/common/ucnv2022.cpp
    ${ICU_SRC_DIR}/common/ucnv_bld.cpp
    ${ICU_SRC_DIR}/common/ucnv_cb.cpp
    ${ICU_SRC_DIR}/common/ucnv_cnv.cpp
    ${ICU_SRC_DIR}/common/ucnv_ct.cpp
    ${ICU_SRC_DIR}/common/ucnv_err.cpp
    ${ICU_SRC_DIR}/common/ucnv_ext.cpp
    ${ICU_SRC_DIR}/common/ucnv_io.cpp
    ${ICU_SRC_DIR}/common/ucnv_lmb.cpp
    ${ICU_SRC_DIR}/common/ucnv_set.cpp
    ${ICU_SRC_DIR}/common/ucnv_u16.cpp
    ${ICU_SRC_DIR}/common/ucnv_u32.cpp
    ${ICU_SRC_DIR}/common/ucnv_u7.cpp
    ${ICU_SRC_DIR}/common/ucnv_u8.cpp
    ${ICU_SRC_DIR}/common/ucnvbocu.cpp
    ${ICU_SRC_DIR}/common/ucnvdisp.cpp
    ${ICU_SRC_DIR}/common/ucnvhz.cpp
    ${ICU_SRC_DIR}/common/ucnvisci.cpp
    ${ICU_SRC_DIR}/common/ucnvlat1.cpp
    ${ICU_SRC_DIR}/common/ucnvmbcs.cpp
    ${ICU_SRC_DIR}/common/ucnvscsu.cpp
    ${ICU_SRC_DIR}/common/ucnvsel.cpp
    ${ICU_SRC_DIR}/common/ucol_swp.cpp
    ${ICU_SRC_DIR}/common/ucptrie.cpp
    ${ICU_SRC_DIR}/common/ucurr.cpp
    ${ICU_SRC_DIR}/common/udata.cpp
    ${ICU_SRC_DIR}/common/udatamem.cpp
    ${ICU_SRC_DIR}/common/udataswp.cpp
    ${ICU_SRC_DIR}/common/uenum.cpp
    ${ICU_SRC_DIR}/common/uhash.cpp
    ${ICU_SRC_DIR}/common/uhash_us.cpp
    ${ICU_SRC_DIR}/common/uidna.cpp
    ${ICU_SRC_DIR}/common/uinit.cpp
    ${ICU_SRC_DIR}/common/uinvchar.cpp
    ${ICU_SRC_DIR}/common/uiter.cpp
    ${ICU_SRC_DIR}/common/ulist.cpp
    ${ICU_SRC_DIR}/common/uloc.cpp
    ${ICU_SRC_DIR}/common/uloc_keytype.cpp
    ${ICU_SRC_DIR}/common/uloc_tag.cpp
    ${ICU_SRC_DIR}/common/umapfile.cpp
    ${ICU_SRC_DIR}/common/umath.cpp
    ${ICU_SRC_DIR}/common/umutablecptrie.cpp
    ${ICU_SRC_DIR}/common/umutex.cpp
    ${ICU_SRC_DIR}/common/unames.cpp
    ${ICU_SRC_DIR}/common/unifiedcache.cpp
    ${ICU_SRC_DIR}/common/unifilt.cpp
    ${ICU_SRC_DIR}/common/unifunct.cpp
    ${ICU_SRC_DIR}/common/uniset.cpp
    ${ICU_SRC_DIR}/common/uniset_closure.cpp
    ${ICU_SRC_DIR}/common/uniset_props.cpp
    ${ICU_SRC_DIR}/common/unisetspan.cpp
    ${ICU_SRC_DIR}/common/unistr.cpp
    ${ICU_SRC_DIR}/common/unistr_case.cpp
    ${ICU_SRC_DIR}/common/unistr_case_locale.cpp
    ${ICU_SRC_DIR}/common/unistr_cnv.cpp
    ${ICU_SRC_DIR}/common/unistr_props.cpp
    ${ICU_SRC_DIR}/common/unistr_titlecase_brkiter.cpp
    ${ICU_SRC_DIR}/common/unorm.cpp
    ${ICU_SRC_DIR}/common/unormcmp.cpp
    ${ICU_SRC_DIR}/common/uobject.cpp
    ${ICU_SRC_DIR}/common/uprops.cpp
    ${ICU_SRC_DIR}/common/ures_cnv.cpp
    ${ICU_SRC_DIR}/common/uresbund.cpp
    ${ICU_SRC_DIR}/common/uresdata.cpp
    ${ICU_SRC_DIR}/common/usc_impl.cpp
    ${ICU_SRC_DIR}/common/uscript.cpp
    ${ICU_SRC_DIR}/common/uscript_props.cpp
    ${ICU_SRC_DIR}/common/uset.cpp
    ${ICU_SRC_DIR}/common/uset_props.cpp
    ${ICU_SRC_DIR}/common/usetiter.cpp
    ${ICU_SRC_DIR}/common/ushape.cpp
    ${ICU_SRC_DIR}/common/usprep.cpp
    ${ICU_SRC_DIR}/common/ustack.cpp
    ${ICU_SRC_DIR}/common/ustr_cnv.cpp
    ${ICU_SRC_DIR}/common/ustr_titlecase_brkiter.cpp
    ${ICU_SRC_DIR}/common/ustr_wcs.cpp
    ${ICU_SRC_DIR}/common/ustrcase.cpp
    ${ICU_SRC_DIR}/common/ustrcase_locale.cpp
    ${ICU_SRC_DIR}/common/ustrenum.cpp
    ${ICU_SRC_DIR}/common/ustrfmt.cpp
    ${ICU_SRC_DIR}/common/ustring.cpp
    ${ICU_SRC_DIR}/common/ustrtrns.cpp
    ${ICU_SRC_DIR}/common/utext.cpp
    ${ICU_SRC_DIR}/common/utf_impl.cpp
    ${ICU_SRC_DIR}/common/util.cpp
    ${ICU_SRC_DIR}/common/util_props.cpp
    ${ICU_SRC_DIR}/common/utrace.cpp
    ${ICU_SRC_DIR}/common/utrie.cpp
    ${ICU_SRC_DIR}/common/utrie2.cpp
    ${ICU_SRC_DIR}/common/utrie2_builder.cpp
    ${ICU_SRC_DIR}/common/utrie_swap.cpp
    ${ICU_SRC_DIR}/common/uts46.cpp
    ${ICU_SRC_DIR}/common/utypes.cpp
    ${ICU_SRC_DIR}/common/uvector.cpp
    ${ICU_SRC_DIR}/common/uvectr32.cpp
    ${ICU_SRC_DIR}/common/uvectr64.cpp
    ${ICU_SRC_DIR}/common/wintz.cpp

    # icudt
    ${ICU_SRC_DIR}/stubdata/stubdata.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

target_compile_definitions(${PROJECT_NAME} PUBLIC
    U_STATIC_IMPLEMENTATION
    U_COMMON_IMPLEMENTATION
)

set_target_properties(${PROJECT_NAME} PROPERTIES ${TARGET_PROPERTIES})

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif()
