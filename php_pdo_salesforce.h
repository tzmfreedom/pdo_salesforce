/* pdo_salesforce extension for PHP */

#ifndef PHP_PDO_SALESFORCE_H
# define PHP_PDO_SALESFORCE_H

extern zend_module_entry pdo_salesforce_module_entry;
# define phpext_pdo_salesforce_ptr &pdo_salesforce_module_entry

# define PHP_PDO_SALESFORCE_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PDO_SALESFORCE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PDO_SALESFORCE_H */
