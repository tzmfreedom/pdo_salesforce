--TEST--
Check if pdo_salesforce is loaded
--SKIPIF--
<?php
if (!extension_loaded('pdo_salesforce')) {
    echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "pdo_salesforce" is available';
?>
--EXPECT--
The extension "pdo_salesforce" is available
