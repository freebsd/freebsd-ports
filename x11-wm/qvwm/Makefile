# New ports collection makefile for:   qvwm
# Version required:    1.1
# Date created:        2 January 1997
# Whom:                Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	qvwm-1.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://www.qvwm.org/pub/qvwm/

MAINTAINER=	nakai@FreeBSD.org

#LIB_DEPENDS=	Imlib.4:${PORTSDIR}/graphics/imlib

USE_IMAKE=	yes
MAN1=		qvwm.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/rc/*.qvwmrc
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/src/Imakefile

.include <bsd.port.mk>
