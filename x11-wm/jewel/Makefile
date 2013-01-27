# Created by: trevor
# $FreeBSD$

PORTNAME=	jewel
PORTVERSION=	0.12.41
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://mjr.towers.org.uk/comp/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Window manager based on aewm++

ALL_TARGET=	all
DOCS=		Changelog Changelog.DLR Changelog.jewel INSTALL LICENSE README
MAN1=		jewel.1x
USE_XORG=	x11 xext xpm
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g; \
		s|^CFLAGS|#CFLAGS|g; \
		s|^prefix|#prefix|g; \
		s|prefix|PREFIX|g; \
		s|/usr/X11R6|${LOCALBASE}|g; \
		s|CC|CXX|g; \
		s|CFLAGS|CXXFLAGS|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jewel ${PREFIX}/bin/jewel
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/appbar/appbar ${PREFIX}/bin/jewel-appbar
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/fspanel/fspanel ${PREFIX}/bin/jewel-fspanel
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/setrootimage/setrootimage ${PREFIX}/bin/jewel-setrootimage
	${INSTALL_PROGRAM} ${WRKSRC}/goodies/xsession/xsession ${PREFIX}/bin/jewel-xsession
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
