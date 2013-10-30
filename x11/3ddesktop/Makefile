# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	3ddesktop
PORTVERSION=	0.2.9
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	SF/desk3d/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Virtual Desktop Switcher

USE_XORG=	xmu
USE_GL=		glut
USE_EFL=	imlib2
GNU_CONFIGURE=	yes

PORTDOCS=	README README.windowmanagers
PLIST_FILES=	bin/3ddesk bin/3ddeskd etc/3ddesktop.conf \
		%%DATADIR%%/digits.bmp \
		man/man1/3ddesk.1.gz man/man1/3ddeskd.1.gz
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT  -pthread
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O3||g ; \
		 s|@ACLOCAL@|${TRUE}|g ; \
		 s|@AUTOCONF@|${TRUE}|g ; \
		 s|@AUTOHEADER@|${TRUE}|g ; \
		 s|@AUTOMAKE@|${TRUE}|g'

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README README.windowmanagers
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
