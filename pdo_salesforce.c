/* pdo_salesforce extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_pdo_salesforce.h"
#include "pdo_salesforce_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

static int pdo_salesforce_handle_factory(pdo_dbh_t *dbh, zval *driver_options) /* {{{ */
{
	pdo_salesforce_db_handle *H;
	int i, ret = 0;
	zend_long timeout = 60, flags;
	char *filename;

//	H = pecalloc(1, sizeof(pdo_sqlite_db_handle), dbh->is_persistent);

	H->einfo.errcode = 0;
	H->einfo.errmsg = NULL;
	dbh->driver_data = H;
    // login salesforce
    // dbh->data_source

	dbh->alloc_own_columns = 1;
	dbh->max_escaped_char_length = 2;

	ret = 1;

cleanup:
	// dbh->methods = &salesforce_methods;

	return ret;
}
/* }}} */

const pdo_driver_t pdo_salesforce_driver = {
	PDO_DRIVER_HEADER(salesforce),
	pdo_salesforce_handle_factory
};

static const struct pdo_dbh_methods salesforce_methods = {
	salesforce_handle_closer,
	salesforce_handle_preparer,
	salesforce_handle_doer,
	salesforce_handle_quoter,
	salesforce_handle_begin,
	salesforce_handle_commit,
	salesforce_handle_rollback,
	pdo_salesforce_set_attr,
	pdo_salesforce_last_insert_id,
	pdo_salesforce_fetch_error_func,
	pdo_salesforce_get_attribute,
	NULL,	/* check_liveness: not needed */
	get_driver_methods,
	pdo_salesforce_request_shutdown,
	NULL, /* in transaction, use PDO's internal tracking mechanism */
	pdo_salesforce_get_gc
};


/* {{{ pdo_salesforce_deps */
static const zend_module_dep pdo_salesforce_deps[] = {
	ZEND_MOD_REQUIRED("pdo")
	ZEND_MOD_END
};
/* }}} */

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "pdo_salesforce");
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(pdo_salesforce)
{
#if defined(ZTS) && defined(COMPILE_DL_PDO_SALESFORCE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(pdo_salesforce)
{
	php_pdo_unregister_driver(&pdo_salesforce_driver);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(pdo_salesforce)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "pdo_salesforce support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ pdo_salesforce_module_entry */
zend_module_entry pdo_salesforce_module_entry = {
	STANDARD_MODULE_HEADER_EX, NULL,
	pdo_salesforce_deps,
	"pdo_salesforce",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(pdo_salesforce),							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(pdo_salesforce),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(pdo_salesforce),			/* PHP_MINFO - Module info */
	PHP_PDO_SALESFORCE_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */


#ifdef COMPILE_DL_PDO_SALESFORCE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(pdo_salesforce)
#endif
