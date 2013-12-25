yum install -y python-devel httpd mod_wsgi php php-devel php-mysql python-repoze-tm2 python-transaction
yum install -y mod_perl mod_python mod_ssl 
yum install -y httpd-devel
easy_install pip
pip install PIL reportlab
easy_install indico

# untar pip.xx.tar.gz
# cd into pip.xxx
# python setup.py install (as root)
