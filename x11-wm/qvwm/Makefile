# New ports collection makefile for:   qvwm
# Version required:    1.1.4
# Date created:        2 January 1997
# Whom:                Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	qvwm-1.1.4
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		esd.2:${PORTSDIR}/audio/esound

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		qvwm.1x

.include <bsd.port.mk>
