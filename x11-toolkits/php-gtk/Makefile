# ports collection makefile for: php-gtk
# Date created: 	03 October 2002
# Whom: 		Alex Kiesel <kiesel@schlund.de>
#
# $FreeBSD$
#

PORTNAME=	php-gtk
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://gtk.php.net/distributions/ \
		http://document-root.de/mirror/php-gtk/

MAINTAINER=	kiesel@schlund.de
COMMENT=	An extension to use gtk in PHP-applications

# Don't call autoconf directly, ./buildconf does this
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WANT_AUTOMAKE_VER=	15
WANT_AUTOCONF_VER=	253
LIBTOOLFILES=	# none
USE_PHPIZE=	yes
USE_AUTOCONF=	no
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/php4/bsd.php.mk"

BUILD_DEPENDS+=	${PREFIX}/bin/php:${PORTSDIR}/lang/php4

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

.if !defined(WITHOUT_SCINTILLA)
BUILD_DEPENDS+=	${X11BASE}/include/scintilla/gtkscintilla.h:${PORTSDIR}/x11-toolkits/gtkscintilla
LIB_DEPENDS+=	gtkscintilla.0:${PORTSDIR}/x11-toolkits/gtkscintilla
ENVSCE+=	-DHAVE_SCINTILLA=1 # -DPHP_GTK_COMPILE_DL_SCINTILLA=1
CONFIGURE_ARGS+=	--enable-scintilla
.endif

.if !defined(WITHOUT_GDK_PIXBUF)
USE_GNOME+=	gdkpixbuf
CONFIGURE_ARGS+=	--enable-gdkpixbuf
ENVSCE+=	-DHAVE_GDKPIXBUF=1 -DPHP_GTK_COMPILE_DL_GDKPIXBUF=1
PLIST_SUB+=	GDKPIXBUF=""
.else
PLIST_SUB+=	GDKPIXBUF="@comment "
.endif

.if !defined(WITHOUT_GTKHTML)
USE_GNOME+=	gtkhtml
CONFIGURE_ARGS+=	--enable-gtkhtml
ENVSCE+=	-DHAVE_HTML=1 -I${X11BASE}/include/gal-1.0 # -DPHP_GTK_COMPILE_DL_GTKHTML=1 -DGTKHTML_HAVE_GCONF=1 -I${X11BASE}/include/gal-1.0
PLIST_SUB+=	GTKHTML=""
.else
PLIST_SUB+=	GTKHTML="@comment "
.endif

PLIST_SUB+=	PHPEXTDIR="${PHP_EXT_DIR}"

CONFIGURE_ENV=	CPPFLAGS="${ENVSCE}"

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

PIC2FIX=	acinclude.m4 aclocal.m4 configure

EXAMPLES=	combobutton.php fileselection.php gtk.php hello.php list.php \
		piemenu.php scribble.php scrollpane.php spaned.php sqpane.php \
		testgtkrc testgtkrc2 window.xpm

pre-everything::
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* By default php-gtk is built with several Gnome deps.  *'
	@${ECHO_MSG} '* If you do not need them, you may define:              *'
	@${ECHO_MSG} '*                                                       *'
	@${ECHO_MSG} '*    - WITHOUT_LIBGLADE                                 *'
	@${ECHO_MSG} '*    - WITHOUT_GDK_PIXBUF                               *'
	@${ECHO_MSG} '*    - WITHOUT_GTKHTML                                  *'
	@${ECHO_MSG} '*    - WITHOUT_SCINTILLA                                *'
	@${ECHO_MSG} '*                                                       *'
	@${ECHO_MSG} '*********************************************************'

pre-configure:
	@php ${SCRIPTDIR}/memlim.php
	@${ECHO_MSG} "===>  Building configuration files for ${PKGNAME}"
	@(cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} ./buildconf)
.for FILE in ${PIC2FIX}
	@${REINPLACE_CMD} -e "s|-prefer-pic|${CFLAGS}|g" ${WRKSRC}/${FILE}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/test/${FILE} ${EXAMPLESDIR}
.endfor
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif
	@${MKDIR} ${PREFIX}/etc/php.gtk
	@${INSTALL_DATA} ${FILESDIR}/php.ini-dist ${PREFIX}/etc/php.gtk
	@${ECHO} ""
	@${CAT} ${MASTERDIR}/pkg-message
	@${ECHO} ""

.include <bsd.port.post.mk>
