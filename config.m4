dnl config.m4 for extension pdo_salesforce

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([pdo_salesforce],
dnl   [for pdo_salesforce support],
dnl   [AS_HELP_STRING([--with-pdo_salesforce],
dnl     [Include pdo_salesforce support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([pdo_salesforce],
  [whether to enable pdo_salesforce support],
  [AS_HELP_STRING([--enable-pdo_salesforce],
    [Enable pdo_salesforce support])],
  [no])

if test "$PHP_PDO_SALESFORCE" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, PDO_SALESFORCE_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-pdo_salesforce -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/pdo_salesforce.h"  # you most likely want to change this
  dnl if test -r $PHP_PDO_SALESFORCE/$SEARCH_FOR; then # path given as parameter
  dnl   PDO_SALESFORCE_DIR=$PHP_PDO_SALESFORCE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for pdo_salesforce files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PDO_SALESFORCE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PDO_SALESFORCE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the pdo_salesforce distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-pdo_salesforce -> add include path
  dnl PHP_ADD_INCLUDE($PDO_SALESFORCE_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-pdo_salesforce -> check for lib and symbol presence
  dnl LIBNAME=PDO_SALESFORCE # you may want to change this
  dnl LIBSYMBOL=PDO_SALESFORCE # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_PDO_SALESFORCE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your pdo_salesforce library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PDO_SALESFORCE_DIR/$PHP_LIBDIR, PDO_SALESFORCE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PDO_SALESFORCE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your pdo_salesforce library.])
  dnl ],[
  dnl   -L$PDO_SALESFORCE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PDO_SALESFORCE_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_PDO_SALESFORCE, 1, [ Have pdo_salesforce support ])

  PHP_NEW_EXTENSION(pdo_salesforce, pdo_salesforce.c, $ext_shared)
fi
