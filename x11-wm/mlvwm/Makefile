# New ports collection makefile for:   mlvwm
# Version required:    0.9.0
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	mlvwm090
PKGNAME=	mlvwm-0.9.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mini-icons.tar.gz

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
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
