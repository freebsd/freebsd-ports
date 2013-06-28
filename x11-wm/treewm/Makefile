# Created by: Rudolf Polzer <freebsd-dr@durchnull.de>
# $FreeBSD$

PORTNAME=	treewm
PORTVERSION=	0.4.5
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager that arranges windows in a tree

LICENSE=	GPLv2

USES=		imake:env

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 ice sm xext xmu xpm xt xxf86vm
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL PROBLEMS README README.tiling TODO
PORTEXAMPLES=	default.cfg sample.cfg

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^PREFIX/s| =| ?=| ; /^CXXFLAGS/s| =| ?=| ; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/treewm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xprop/xprop ${PREFIX}/bin/xprop-treewm
	${INSTALL_PROGRAM} ${WRKSRC}/xkill/xkill ${PREFIX}/bin/xkill-treewm
	@${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/pixmaps/*.xpm ${DATADIR}/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
