# ports collection makefile for: php-gtk2
# Date created: 	01 July 2009
# Whom: 		Kris Moore <kmoore@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	php-gtk2
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://gtk.php.net/distributions/ \
		http://document-root.de/mirror/php-gtk/
DISTNAME=	php-gtk-${PORTVERSION}

MAINTAINER=	kmoore@freebsd.org
COMMENT=	An extension to use gtk2 in PHP-applications

BROKEN=		does not compile

USE_AUTOTOOLS=	automake:111:env autoconf:267 libtool:22:env
USE_PHP=	pcre
USE_PHP_BUILD=	yes
WANT_PHP_CLI=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
WRKSRC=${WRKDIR}/php-gtk-${PORTVERSION}
PORTSCOUT=	limit:^1\.

OPTIONS=	LIBGLADE	"GladeXML support in php-gtk2"	on

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

# Fix environment for self contained extensions
ENVSCE=		-DHAVE_PHP_GTK=1 -DCOMPILE_DL_PHP_GTK=1	\
		-DHAVE_PIEMENU=1	\
		-DHAVE_SCROLLPANE=1	\
		-DHAVE_SPANED=1		\
		-DHAVE_SQPANE=1		\
		-DHAVE_COMBOBUTTON=1

.if !defined(WITHOUT_LIBGLADE)
USE_GNOME+=	libglade
ENVSCE+=	-DHAVE_LIBGLADE
.else
CONFIGURE_ARGS+=	--disable-libglade
.endif

PLIST_SUB+=	PHPEXTDIR="${PHP_EXT_DIR}"

CONFIGURE_ENV=	CPPFLAGS="${ENVSCE}"

REINPLACE_ARGS=	-i ""

PIC2FIX=	acinclude.m4 aclocal.m4 configure

EXAMPLES=	combobutton.php fileselection.php gtk.php hello.php list.php \
		piemenu.php scribble.php scrollpane.php spaned.php sqpane.php \
		testgtkrc testgtkrc2 window.xpm

PKGMESSAGE=	${WRKDIR}/pkg-message

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g" \
	${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

pre-configure:
	@${ECHO_MSG} "===>  Building configuration files for ${PKGNAME}"
	@(cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} \
	PHP_AUTOCONF=${AUTOCONF} PHP_AUTOHEADER=${AUTOHEADER} ./buildconf)
	@${REINPLACE_CMD} -e "s|/bin/sh|/bin/sh -x|" ${WRKSRC}/configure
.for FILE in ${PIC2FIX}
	@${REINPLACE_CMD} -e "s|-prefer-pic|${CFLAGS}|g" ${WRKSRC}/${FILE}
.endfor

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/test/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif
	@${CAT}	${PKGMESSAGE}
	@${MKDIR} ${PREFIX}/etc/php
	@${ECHO_CMD} extension=php_gtk2.so \
		>> ${PREFIX}/etc/php/extensions.ini

.include <bsd.port.post.mk>
