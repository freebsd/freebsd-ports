# ports collection makefile for: php-gtk
# Date created: 	03 October 2002
# Whom: 		Alex Kiesel <kiesel@schlund.de>
#
# $FreeBSD$
#

PORTNAME=	php-gtk
PORTVERSION=	1.0.2
PORTREVISION=	12
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://gtk.php.net/distributions/ \
		http://document-root.de/mirror/php-gtk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extension to use gtk in PHP-applications

DEPRECATED=	Abandoned upstream, consider using x11-toolkits/php-gtk2
EXPIRATION_DATE=	2011-05-01

USE_AUTOTOOLS=	automake:env autoconf libtool:env
GNU_CONFIGURE=	yes
USE_PHP=	pcre
USE_PHP_BUILD=	yes
WANT_PHP_CLI=	yes
IGNORE_WITH_PHP=	5
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
WRKSRC=${WRKDIR}/php_gtk-${PORTVERSION}
PORTSCOUT=	limit:^1\.

OPTIONS=	LIBGLADE	"GladeXML support in php-gtk" on \
		GDK_PIXBUF	"Enable pixbuf support" on

.include <bsd.port.pre.mk>

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

.if !defined(WITHOUT_GDK_PIXBUF)
USE_GNOME+=	gdkpixbuf
CONFIGURE_ARGS+=	--enable-gdkpixbuf
ENVSCE+=	-DHAVE_GDKPIXBUF=1 -DPHP_GTK_COMPILE_DL_GDKPIXBUF=1
PLIST_SUB+=	GDKPIXBUF=""
.else
PLIST_SUB+=	GDKPIXBUF="@comment "
.endif

PLIST_SUB+=	PHPEXTDIR="${PHP_EXT_DIR}"

CONFIGURE_ENV=	CPPFLAGS="${ENVSCE}"

REINPLACE_ARGS=	-i ""

PIC2FIX=	acinclude.m4 aclocal.m4 configure

EXAMPLES=	combobutton.php fileselection.php gtk.php hello.php list.php \
		piemenu.php scribble.php scrollpane.php spaned.php sqpane.php \
		testgtkrc testgtkrc2 window.xpm

pre-configure:
	@${ECHO_MSG} "===>  Building configuration files for ${PKGNAME}"
	@(cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} PHP_AUTOCONF=${AUTOCONF} PHP_AUTOHEADER=${AUTOHEADER} ./buildconf)
.for FILE in ${PIC2FIX}
	@${REINPLACE_CMD} -e "s|-prefer-pic|${CFLAGS}|g" ${WRKSRC}/${FILE}
.endfor
	@${REINPLACE_CMD} -e "s|/bin/sh|/bin/sh -x|" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/test/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.post.mk>
