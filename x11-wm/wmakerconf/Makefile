# New ports collection makefile for:	wmakerconf
# Date Created:				14 August 1999
# Whom:					Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	wmakerconf
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_NETBSD}

MAINTAINER=	nc-rotherdo@netcologne.de
COMMENT=	A configuration tool for Window Maker

RUN_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bunzip2:${PORTSDIR}/archivers/bzip2
.endif
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		wraster.4:${PORTSDIR}/x11-wm/windowmaker

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_GNOME=	imlib
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wmakerdir="${X11BASE}/share/WindowMaker"

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
BUILD_DEPENDS+=	gnome2wmaker:${PORTSDIR}/x11-wm/gnome2wmaker
RUN_DEPENDS+=	gnome2wmaker:${PORTSDIR}/x11-wm/gnome2wmaker
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

post-configure:
	@${PERL} -pi -e 's|%%X11BASE%%|${X11BASE}| ; s|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/data/WMWmakerconf.gettext ${WRKSRC}/data/WMWmakerconf

.include <bsd.port.post.mk>
