# New ports collection makefile for:	icewm
# Date created:		10 August 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	icewm
PORTVERSION=	1.0.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.sourceforge.net/icewm/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	nakai@FreeBSD.org

.if defined(GNOME)
LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs
.endif
LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS+=	--enable-i18n

post-install:
	${INSTALL_DATA} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/share/icewm/taskbar

.include <bsd.port.mk>
