# New ports collection makefile for:   mlvwm
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mlvwm
PORTVERSION=	0.9.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm/
DISTNAME=	mlvwm091
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mini-icons.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Macintosh like window manager for X11

USE_IMAKE=	yes
USE_PERL5_BUILD=yes
USE_XPM=	yes
MAN1=		mlvwm.1

MLVWMLIBDIR=	${PREFIX}/lib/X11/mlvwm

post-extract:
	@${TAR} -C ${WRKSRC}/pixmap -xzf ${DISTDIR}/mini-icons.tar.gz

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/sample_rc/Mlvwmrc*

post-install:
	@${RM} -f ${WRKSRC}/sample_rc/*.orig
	@${MKDIR} ${MLVWMLIBDIR}/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${MLVWMLIBDIR}/pixmap
	${INSTALL_DATA} ${WRKSRC}/sample_rc/Mlvwmrc* ${MLVWMLIBDIR}

.include <bsd.port.mk>
