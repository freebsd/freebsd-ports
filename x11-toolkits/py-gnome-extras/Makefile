# New ports collection makefile for:	py-gnome-extras
# Date created:				22 November 2005
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome
PORTVERSION=	2.10.2
CATEGORIES=	x11-toolkits python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-python-extras/${PORTVERSION:C/..$//}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-extras
DISTNAME=	gnome-python-extras-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for GNOME 2

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2 \
		gtop-2.0.2:${PORTSDIR}/devel/libgtop2 \
		totem-plparser.0:${PORTSDIR}/multimedia/totem-gstreamer
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZILLA=	mozilla
HEADERS_SUFX=
MOZ_BUILD=	mozilla

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
MOZ_BUILD=	firefox
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
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack libgnomeprintui libgtkhtml gnomepanel \
		gtksourceview libwnck nautiluscdburner pygnome2
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-gtkmozembed=${MOZ_BUILD}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${PREFIX}/share/examples/py-gnome

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
.if ${MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
.endif
.endif

.if exists(${X11BASE}/lib/libgdl-1.so)
LIB_DEPENDS+=	gdl-1:${PORTSDIR}/x11-toolkits/gdl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g ; \
		s|mozilla-xpcom|mozilla-xpcom${HEADERS_SUFX}|g ; \
		s|$$MOZILLA-gtkmozembed|$$MOZILLA-gtkmozembed${HEADERS_SUFX}|g ; \
		s|$$MOZILLA-xpcom|$$MOZILLA-xpcom${HEADERS_SUFX}|g' \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default py-gnome-extras uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  firefox       "
	@${ECHO_MSG} "  mozilla-devel "
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
