 --- kdeprint/cups/cupsdconf2/cups-util.c-orig	2007-10-02 21:36:37.442645546 -0500
 +++ kdeprint/cups/cupsdconf2/cups-util.c	2007-10-02 21:42:08.991708625 -0500
 @@ -6,489 +6,118 @@
  #include <sys/stat.h>
  #include <unistd.h>
  
 -#define CUPS_SERVERROOT	"/etc/cups"
 -static http_t		*cups_server;
  static ipp_status_t	last_error;
 -static char		authstring[HTTP_MAX_VALUE];
 -static char		pwdstring[33];
 -static int cups_local_auth(http_t *http);
  
 -const char *				/* O - Filename for PPD file */
 +const char* cupsGetConf(void);
 +int cupsPutConf(const char*);
 +
 +const char *    /* O - Filename for PPD file */
  cupsGetConf(void)
  {
 -  int		fd;			/* PPD file */
 -  int		bytes;			/* Number of bytes read */
 -  char		buffer[8192];		/* Buffer for file */
 -  char		resource[HTTP_MAX_URI];	/* Resource name */
 -  const char	*password;		/* Password string */
 -  char		realm[HTTP_MAX_VALUE],	/* realm="xyz" string */
 -		nonce[HTTP_MAX_VALUE],	/* nonce="xyz" string */
 -		plain[255],		/* Plaintext username:password */
 -		encode[512];		/* Encoded username:password */
 -  http_status_t	status;			/* HTTP status from server */
 -  char		prompt[1024];		/* Prompt string */
 -  int		digest_tries;		/* Number of tries with Digest */
 -  static char	filename[HTTP_MAX_URI];	/* Local filename */
 -
 - /*
 -  * Connect to the correct server as needed...
 -  */
 -
 -    if ((cups_server = httpConnectEncrypt(cupsServer(), ippPort(),
 -                                          cupsEncryption())) == NULL)
 -    {
 -      last_error = IPP_SERVICE_UNAVAILABLE;
 -      return (NULL);
 -    }
 -
 - /*
 -  * Get a temp file...
 -  */
 -
 -  if ((fd = cupsTempFd(filename, sizeof(filename))) < 0)
 -  {
 -   /*
 -    * Can't open file; close the server connection and return NULL...
 -    */
 -
 -    httpFlush(cups_server);
 -    httpClose(cups_server);
 -    cups_server = NULL;
 -    return (NULL);
 -  }
 -
 - /*
 -  * And send a request to the HTTP server...
 -  */
 -
 -  snprintf(resource, sizeof(resource), "/admin/conf/cupsd.conf");
 -
 -  digest_tries = 0;
 -
 -  do
 -  {
 -    httpClearFields(cups_server);
 -    httpSetField(cups_server, HTTP_FIELD_HOST, cupsServer());
 -    httpSetField(cups_server, HTTP_FIELD_AUTHORIZATION, authstring);
 -
 -    if (httpGet(cups_server, resource))
 -    {
 -      if (httpReconnect(cups_server))
 -      {
 -        status = HTTP_ERROR;
 -	break;
 -      }
 -      else
 -      {
 -        status = HTTP_UNAUTHORIZED;
 -        continue;
 -      }
 -    }
 -
 -    while ((status = httpUpdate(cups_server)) == HTTP_CONTINUE);
 -
 -    if (status == HTTP_UNAUTHORIZED)
 -    {
 -      fprintf(stderr,"cupsGetConf: unauthorized...\n");
 -
 -     /*
 -      * Flush any error message...
 -      */
 -
 -      httpFlush(cups_server);
 -
 -     /*
 -      * See if we can do local authentication...
 -      */
 -
 -      if (cups_local_auth(cups_server))
 -        continue;
 -
 -     /*
 -      * See if we should retry the current digest password...
 -      */
 -
 -      if (strncmp(cups_server->fields[HTTP_FIELD_WWW_AUTHENTICATE], "Basic", 5) == 0 ||
 -          digest_tries > 1 || !pwdstring[0])
 -      {
 -       /*
 -	* Nope - get a password from the user...
 -	*/
 -
 -	snprintf(prompt, sizeof(prompt), "Password for %s on %s? ", cupsUser(),
 -        	 cups_server->hostname);
 -
 -        if ((password = cupsGetPassword(prompt)) == NULL)
 -	  break;
 -	if (!password[0])
 -	  break;
 -
 -        strncpy(pwdstring, password, sizeof(pwdstring) - 1);
 -	pwdstring[sizeof(pwdstring) - 1] = '\0';
 -
 -        digest_tries = 0;
 -      }
 -      else
 -        digest_tries ++;
 -
 -     /*
 -      * Got a password; encode it for the server...
 -      */
 -
 -      if (strncmp(cups_server->fields[HTTP_FIELD_WWW_AUTHENTICATE], "Basic", 5) == 0)
 -      {
 -       /*
 -	* Basic authentication...
 -	*/
 -
 -	snprintf(plain, sizeof(plain), "%s:%s", cupsUser(), pwdstring);
 -#if CUPS_VERSION_MAJOR == 1 && CUPS_VERSION_MINOR >= 2
 -       httpEncode64_2(encode, sizeof(encode), plain, sizeof(plain));
 -#else
 -       httpEncode64(encode, plain);
 -#endif
 -	snprintf(authstring, sizeof(authstring), "Basic %s", encode);
 -      }
 -      else
 -      {
 -       /*
 -	* Digest authentication...
 -	*/
 -
 -        httpGetSubField(cups_server, HTTP_FIELD_WWW_AUTHENTICATE, "realm", realm);
 -        httpGetSubField(cups_server, HTTP_FIELD_WWW_AUTHENTICATE, "nonce", nonce);
 -
 -	httpMD5(cupsUser(), realm, pwdstring, encode);
 -	httpMD5Final(nonce, "GET", resource, encode);
 -	snprintf(authstring, sizeof(authstring),
 -	         "Digest username=\"%s\", realm=\"%s\", nonce=\"%s\", "
 -	         "response=\"%s\"", cupsUser(), realm, nonce, encode);
 -      }
 -
 -      continue;
 -    }
 -#ifdef HAVE_LIBSSL
 -    else if (status == HTTP_UPGRADE_REQUIRED)
 -    {
 -     /*
 -      * Flush any error message...
 -      */
 -
 -      httpFlush(cups_server);
 -
 -     /*
 -      * Upgrade with encryption...
 -      */
 -
 -      httpEncryption(cups_server, HTTP_ENCRYPT_REQUIRED);
 -
 -     /*
 -      * Try again, this time with encryption enabled...
 -      */
 -
 -      continue;
 -    }
 -#endif /* HAVE_LIBSSL */
 -  }
 -  while (status == HTTP_UNAUTHORIZED || status == HTTP_UPGRADE_REQUIRED);
 -
 - /*
 -  * See if we actually got the file or an error...
 -  */
 +    int  fd;   /* PPD file */
 +    http_status_t status;   /* HTTP status from server */
 +    http_t *cups_server;
 +    static char filename[HTTP_MAX_URI]; /* Local filename */
 +    char          fqdn[ HTTP_MAX_URI ];   /* Server name buffer */
 +
 +
 +    /*
 +     * Connect to the correct server as needed...
 +     */
 +
 +    cups_server = httpConnectEncrypt(cupsServer(), ippPort(), cupsEncryption());
 +    if (cups_server == NULL) {
 +        last_error = IPP_SERVICE_UNAVAILABLE;
 +        return (NULL);
 +    }
 +
 +    /*
 +     * Get a temp file...
 +     */
 +
 +    fd = cupsTempFd(filename, sizeof(filename));
 +    if (fd < 0) {
 +        /*
 +         * Can't open file; close the server connection and return NULL...
 +         */
 +
 +        httpFlush(cups_server);
 +        httpClose(cups_server);
 +        cups_server = NULL;
 +        return (NULL);
 +    }
 +
 +    /*
 +     * And send a request to the HTTP server...
 +     */
 +    status = cupsGetFd(cups_server, "/admin/conf/cupsd.conf", fd);
  
 -  if (status != HTTP_OK)
 -  {
      close(fd);
 -    unlink(filename);
      httpFlush(cups_server);
      httpClose(cups_server);
      cups_server = NULL;
 -    return (NULL);
 -  }
 -
 - /*
 -  * OK, we need to copy the file...
 -  */
  
 -  while ((bytes = httpRead(cups_server, buffer, sizeof(buffer))) > 0)
 -  {
 -    write(fd, buffer, bytes);
 -  }
 -
 -  close(fd);
 -
 -  return (filename);
 +    if (status != HTTP_OK) {
 +        unlink(filename);
 +        return (NULL);
 +    } else {
 +        return (filename);
 +    }
  }
  
 -int					/* O - Status of operation */
 -cupsPutConf(const char *name)		/* I - Name of the config file to send */
 +int     /* O - Status of operation */
 +cupsPutConf(const char *name)  /* I - Name of the config file to send */
  {
 -  int		fd;			/* PPD file */
 -  int		bytes;			/* Number of bytes read */
 -  char		buffer[8192];		/* Buffer for file */
 -  char		resource[HTTP_MAX_URI];	/* Resource name */
 -  const char	*password;		/* Password string */
 -  char		realm[HTTP_MAX_VALUE],	/* realm="xyz" string */
 -		nonce[HTTP_MAX_VALUE],	/* nonce="xyz" string */
 -		plain[255],		/* Plaintext username:password */
 -		encode[512];		/* Encoded username:password */
 -  http_status_t	status;			/* HTTP status from server */
 -  char		prompt[1024];		/* Prompt string */
 -  int		digest_tries;		/* Number of tries with Digest */
 -
 -  if (name == NULL)
 -    return 0;
 -
 - /*
 -  * Connect to the correct server as needed...
 -  */
 -
 -    if ((cups_server = httpConnectEncrypt(cupsServer(), ippPort(),
 -                                          cupsEncryption())) == NULL)
 -    {
 -      last_error = IPP_SERVICE_UNAVAILABLE;
 -      return 0;
 -    }
 +    int  fd;   /* PPD file */
 +    http_status_t status;   /* HTTP status from server */
 +    http_t *cups_server;
  
 - /*
 -  * Open the local config file...
 -  */
 -
 -  if ((fd = open(name, O_RDONLY)) < 0)
 -  {
 -   /*
 -    * Can't open file; close the server connection and return NULL...
 -    */
 +    if (name == NULL)
 +        return 0;
  
 -    httpFlush(cups_server);
 -    httpClose(cups_server);
 -    cups_server = NULL;
 -    return 0;
 -  }
 +    /*
 +     * Connect to the correct server as needed...
 +     */
  
 - /*
 -  * And send a request to the HTTP server...
 -  */
 -
 -  strncpy(resource, "/admin/conf/cupsd.conf", sizeof(resource));
 -
 -  digest_tries = 0;
 -
 -  do
 -  {
 -    httpClearFields(cups_server);
 -    httpSetField(cups_server, HTTP_FIELD_HOST, cupsServer());
 -    httpSetField(cups_server, HTTP_FIELD_AUTHORIZATION, authstring);
 -    httpSetField(cups_server, HTTP_FIELD_TRANSFER_ENCODING, "chunked");
 -
 -    if (httpPut(cups_server, resource))
 -    {
 -      if (httpReconnect(cups_server))
 -      {
 -        status = HTTP_ERROR;
 -	break;
 -      }
 -      else
 -      {
 -        status = HTTP_UNAUTHORIZED;
 -        continue;
 -      }
 +    cups_server = httpConnectEncrypt(cupsServer(), ippPort(), cupsEncryption());
 +    if (cups_server == NULL) {
 +        last_error = IPP_SERVICE_UNAVAILABLE;
 +        return 0;
      }
  
 -    /* send the file now */
 -    lseek(fd, 0, SEEK_SET);
 -    status = HTTP_CONTINUE;
 -    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0)
 -        if (httpCheck(cups_server))
 -	{
 -	    if ((status = httpUpdate(cups_server)) != HTTP_CONTINUE)
 -	        break;
 -	}
 -	else
 -	    httpWrite(cups_server, buffer, bytes);
 -
 -    if (status == HTTP_CONTINUE)
 -    {
 -        httpWrite(cups_server, buffer, 0);
 -	while ((status = httpUpdate(cups_server)) == HTTP_CONTINUE);
 -    }
 +    /*
 +     * Open the local config file...
 +     */
  
 -    if (status == HTTP_UNAUTHORIZED)
 -    {
 -      fprintf(stderr,"cupsPutConf: unauthorized...");
 -
 -     /*
 -      * Flush any error message...
 -      */
 -
 -      httpFlush(cups_server);
 -
 -     /*
 -      * See if we can do local authentication...
 -      */
 -
 -      if (cups_local_auth(cups_server))
 -        continue;
 -
 -     /*
 -      * See if we should retry the current digest password...
 -      */
 -
 -      if (strncmp(cups_server->fields[HTTP_FIELD_WWW_AUTHENTICATE], "Basic", 5) == 0 ||
 -          digest_tries > 1 || !pwdstring[0])
 -      {
 -       /*
 -	* Nope - get a password from the user...
 -	*/
 -
 -	snprintf(prompt, sizeof(prompt), "Password for %s on %s? ", cupsUser(),
 -        	 cups_server->hostname);
 -
 -        if ((password = cupsGetPassword(prompt)) == NULL)
 -	  break;
 -	if (!password[0])
 -	  break;
 -
 -        strncpy(pwdstring, password, sizeof(pwdstring) - 1);
 -	pwdstring[sizeof(pwdstring) - 1] = '\0';
 -
 -        digest_tries = 0;
 -      }
 -      else
 -        digest_tries ++;
 -
 -     /*
 -      * Got a password; encode it for the server...
 -      */
 -
 -      if (strncmp(cups_server->fields[HTTP_FIELD_WWW_AUTHENTICATE], "Basic", 5) == 0)
 -      {
 -       /*
 -	* Basic authentication...
 -	*/
 -
 -	snprintf(plain, sizeof(plain), "%s:%s", cupsUser(), pwdstring);
 -#if CUPS_VERSION_MAJOR == 1 && CUPS_VERSION_MINOR >= 2
 -       httpEncode64_2(encode, sizeof(encode), plain, sizeof(plain));
 -#else
 -       httpEncode64(encode, plain);
 -#endif
 -	snprintf(authstring, sizeof(authstring), "Basic %s", encode);
 -      }
 -      else
 -      {
 -       /*
 -	* Digest authentication...
 -	*/
 -
 -        httpGetSubField(cups_server, HTTP_FIELD_WWW_AUTHENTICATE, "realm", realm);
 -        httpGetSubField(cups_server, HTTP_FIELD_WWW_AUTHENTICATE, "nonce", nonce);
 -
 -	httpMD5(cupsUser(), realm, pwdstring, encode);
 -	httpMD5Final(nonce, "GET", resource, encode);
 -	snprintf(authstring, sizeof(authstring),
 -	         "Digest username=\"%s\", realm=\"%s\", nonce=\"%s\", "
 -	         "response=\"%s\"", cupsUser(), realm, nonce, encode);
 -      }
 +    fd = open(name, O_RDONLY);
 +    if (fd < 0) {
 +        /*
 +         * Can't open file; close the server connection and return NULL...
 +         */
  
 -      continue;
 +        httpFlush(cups_server);
 +        httpClose(cups_server);
 +        cups_server = NULL;
 +        return 0;
      }
 -#ifdef HAVE_LIBSSL
 -    else if (status == HTTP_UPGRADE_REQUIRED)
 -    {
 -     /*
 -      * Flush any error message...
 -      */
 -
 -      httpFlush(cups_server);
 -
 -     /*
 -      * Upgrade with encryption...
 -      */
 -
 -      httpEncryption(cups_server, HTTP_ENCRYPT_REQUIRED);
 -
 -     /*
 -      * Try again, this time with encryption enabled...
 -      */
  
 -      continue;
 -    }
 -#endif /* HAVE_LIBSSL */
 -  }
 -  while (status == HTTP_UNAUTHORIZED || status == HTTP_UPGRADE_REQUIRED);
 -
 - /*
 -  * See if we actually got the file or an error...
 -  */
 +    /*
 +     * And send a request to the HTTP server...
 +     */
 +
 +    status = cupsPutFd(cups_server, "/admin/conf/cupsd.conf", fd);
  
 -  if (status != HTTP_CREATED)
 -  {
      httpFlush(cups_server);
      httpClose(cups_server);
      cups_server = NULL;
      close(fd);
 -    return 0;
 -  }
 -
 -  close(fd);
 -
 -  return 1;
 -}
 -
 -static int			/* O - 1 if available, 0 if not */
 -cups_local_auth(http_t *http)	/* I - Connection */
 -{
 -  int		pid;		/* Current process ID */
 -  FILE		*fp;		/* Certificate file */
 -  char		filename[1024],	/* Certificate filename */
 -		certificate[33];/* Certificate string */
 -  const char	*root;		/* Server root directory */
 -
 -
 - /*
 -  * See if we are accessing localhost...
 -	the struct has changed in newer versions - PiggZ (adam@piggz.co.uk)
 -  */
 -#if CUPS_VERSION_MAJOR == 1 && CUPS_VERSION_MINOR >= 2
 -        if (!httpAddrLocalhost(http))
 -#else
 -	if (ntohl(*(int*)&http->hostaddr.sin_addr) != 0x7f000001 &&
 -      strcasecmp(http->hostname, "localhost") != 0)
 -#endif
 -   return (0);
 -
 - /*
 -  * Try opening a certificate file for this PID.  If that fails,
 -  * try the root certificate...
 -  */
 -
 -  if ((root = getenv("CUPS_SERVERROOT")) == NULL)
 -    root = CUPS_SERVERROOT;
 -
 -  pid = getpid();
 -  snprintf(filename, sizeof(filename), "%s/certs/%d", root, pid);
 -  if ((fp = fopen(filename, "r")) == NULL && pid > 0)
 -  {
 -    snprintf(filename, sizeof(filename), "%s/certs/0", root);
 -    fp = fopen(filename, "r");
 -  }
 -
 -  if (fp == NULL)
 -    return (0);
 -
 - /*
 -  * Read the certificate from the file...
 -  */
 -
 -  fgets(certificate, sizeof(certificate), fp);
 -  fclose(fp);
 -
 - /*
 -  * Set the authorization string and return...
 -  */
 -
 -  snprintf(authstring, sizeof(authstring), "Local %s", certificate);
  
 -  return (1);
 +    /*
 +     * See if we actually got the file or an error...
 +     */
 +
 +    if (status != HTTP_CREATED)
 +        return 0;
 +    else
 +        return 1;
  }
 
 --Boundary-00=_tTyAHs9qWLGFusu
 Content-Type: text/x-c++src;
   charset="us-ascii";
   name="patch-kdeprint_cups_ipprequest.cpp"
 Content-Transfer-Encoding: 7bit
 Content-Disposition: attachment;
 	filename="patch-kdeprint_cups_ipprequest.cpp"
 
 --- kdeprint/cups/ipprequest.cpp-orig	2007-01-15 05:34:19.000000000 -0600
 +++ kdeprint/cups/ipprequest.cpp	2007-10-02 22:21:52.359893129 -0500
 @@ -310,7 +310,7 @@
  	}
  
  #ifdef HAVE_CUPS_NO_PWD_CACHE
 -	strncpy( HTTP->authstring, cups_authstring.data(), HTTP_MAX_VALUE );
 +	httpSetAuthString( HTTP, NULL, cups_authstring.data() );
  #endif
  
  	if (dump_ > 0)
 @@ -320,7 +320,7 @@
  
  	request_ = cupsDoFileRequest(HTTP, request_, (res.isEmpty() ? "/" : res.latin1()), (filename.isEmpty() ? NULL : filename.latin1()));
  #ifdef HAVE_CUPS_NO_PWD_CACHE
 -	cups_authstring = HTTP->authstring;
 +	cups_authstring = httpGetAuthString( HTTP );
  #endif
  	httpClose(HTTP);
