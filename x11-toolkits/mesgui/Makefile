# ex:ts=8
# Ports collection makefile for:	mesgui
# Date created:			Jul 24, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	mesgui
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make a simple GUI under OpenGL

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=	sdl
USE_GL=		gl
USE_GMAKE=	yes
MAKE_ENV=	OPT="${OPT}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

OPT=		${CFLAGS} -fPIC -DPIC -Iinclude \
		`${SDL_CONFIG} --cflags` `freetype-config --cflags` \
		-I${LOCALBASE}/include
LDFLAGS=	`${SDL_CONFIG} --libs` `freetype-config --libs` \
		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^OPT|#OPT|g ; \
		 s|gcc|\$$\(CC\)|g ; \
		 s|-lc|\$$\(LDFLAGS\)|g' ${WRKSRC}/Makefile
	@cd ${WRKSRC}/src && \
	for file in * ; do \
		${MV} $${file} $${file}.pre_tr ; \
		${TR} -d "\r" < $${file}.pre_tr > $${file} ; \
	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/mesgui.h ${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libmesgui.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libmesgui.so.1.0 ${PREFIX}/lib/libmesgui.so.1
	${LN} -fs ${PREFIX}/lib/libmesgui.so.1 ${PREFIX}/lib/libmesgui.so

.include <bsd.port.mk>
