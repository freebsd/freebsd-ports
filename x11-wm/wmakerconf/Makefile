# New ports collection makefile for:	wmakerconf
# Date Created:				14 August 1999
# Whom:					Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	wmakerconf
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://ulli.linuxave.net/wmakerconf/

MAINTAINER=	dr@domix.de

RUN_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm \
		bunzip2:${PORTSDIR}/archivers/bzip2
LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.4:${PORTSDIR}/graphics/png \
		wraster.3:${PORTSDIR}/x11-wm/windowmaker \
		wmfun.1:${PORTSDIR}/x11-wm/windowmaker

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_XPM=	yes
USE_IMLIB=	yes
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
