# Created by: Rudolf Polzer
# $FreeBSD$

PORTNAME=	treewm
PORTVERSION=	0.4.5
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Manager that arranges the windows in a tree

LICENSE=	GPLv2

BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_BZIP2=	yes
USE_XORG=	x11 ice sm xext xmu xpm xt xxf86vm
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS ChangeLog INSTALL PROBLEMS README README.tiling TODO
PORTEXAMPLES=	default.cfg sample.cfg

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^PREFIX/s| =| ?=| ; \
		/^CXXFLAGS/s| =| ?=| ; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/treewm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xprop/xprop ${PREFIX}/bin/xprop-treewm
	${INSTALL_PROGRAM} ${WRKSRC}/xkill/xkill ${PREFIX}/bin/xkill-treewm
	${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/pixmaps/*.xpm ${DATADIR}/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for F in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for F in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${F} ${EXAMPLESDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
