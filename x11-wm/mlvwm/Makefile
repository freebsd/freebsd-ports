# New ports collection makefile for:   mlvwm
# Date created:        19 Januruary 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mlvwm
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www2u.biglobe.ne.jp/~y-miyata/mlvwm/
DISTNAME=	mlvwm091
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mini-icons.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Macintosh like window manager for X11

DEPRECATED=		Project is dead
EXPIRATION_DATE=	2007-10-28

USE_IMAKE=	yes
USE_PERL5_BUILD=yes
USE_XPM=	yes
MAN1=		mlvwm.1

MLVWMLIBDIR=	${PREFIX}/lib/X11/mlvwm

post-extract:
	@${TAR} -C ${WRKSRC}/pixmap -xzf ${DISTDIR}/mini-icons.tar.gz

post-patch:
.for file in configure.h
	@${REINPLACE_CMD} -e \
		's|^.*CDEBUGFLAGS =.*$$||g ; \
		 s|^ICONPATH =.*$$|ICONPATH = $$(INCROOT)/X11/pixmaps|g ; \
		 s|-lxpg4||g' ${WRKSRC}/${file}
.endfor
.for file in Mlvwmrc Mlvwmrc-j
	@${REINPLACE_CMD} -e \
		's|^IconPath .*$$|IconPath ${MLVWMLIBDIR}/pixmap|g ; \
		 s|kterm|xterm|g' ${WRKSRC}/sample_rc/${file}
.endfor

post-install:
	@${MKDIR} ${MLVWMLIBDIR}
.for file in Mlvwmrc Mlvwmrc-Kterm-j Mlvwmrc-Netscape Mlvwmrc-Xterm Mlvwmrc-j
	${INSTALL_DATA} ${WRKSRC}/sample_rc/${file} ${MLVWMLIBDIR}
.endfor
	@${MKDIR} ${MLVWMLIBDIR}/pixmap
	${INSTALL_DATA} ${WRKSRC}/pixmap/*.xpm ${MLVWMLIBDIR}/pixmap

.include <bsd.port.mk>
