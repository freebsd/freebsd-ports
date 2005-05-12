# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yelp
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-doc-utils.pc:${PORTSDIR}/textproc/gnomedocutils \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-doc-utils.pc:${PORTSDIR}/textproc/gnomedocutils \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla
HEADERS_SUFX=

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
.else
.if ${WITH_MOZILLA}=="mozilla-devel" || ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	mozilla-devel
HEADERS_SUFX=	-devel
.else
MOZILLA=	mozilla
HEADERS_SUFX=
.endif
.endif
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-mozilla=${MOZILLA}
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GCONF_SCHEMAS=	yelp.schemas

OPTIONS=	MAN "Enable man page support" off \
		INFO "Enable GNU info support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
.if ${MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
.endif
.endif

.if defined(WITH_MAN)
CONFIGURE_ARGS+=--enable-man
.endif

.if defined(WITH_INFO)
CONFIGURE_ARGS+=--enable-info
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default yelp uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel "
	@${ECHO_MSG} "  firefox "
	@${ECHO_MSG} ""

post-patch:
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="mozilla-devel"
	@${REINPLACE_CMD} -e 's|xmozilla|xmozilla-devel|g; \
		s|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g; \
		s|$$MOZILLA-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g' \
		${WRKSRC}/configure
.endif

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g' <${FILESDIR}/yelp.sh \
		> ${WRKDIR}/yelp.sh
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g' <${FILESDIR}/gnome-help.sh \
		> ${WRKDIR}/gnome-help.sh

post-install:
	${MV} -f ${PREFIX}/bin/yelp ${PREFIX}/bin/yelp-bin
	${MV} -f ${PREFIX}/bin/gnome-help ${PREFIX}/bin/gnome-help-bin
	${INSTALL_SCRIPT} ${WRKDIR}/yelp.sh ${PREFIX}/bin/yelp
	${INSTALL_SCRIPT} ${WRKDIR}/gnome-help.sh ${PREFIX}/bin/gnome-help

.include <bsd.port.post.mk>
