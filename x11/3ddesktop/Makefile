# New ports collection makefile for:	3ddesktop
# Date created:				12 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	3ddesktop
PORTVERSION=	0.2.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	desk3d

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Virtual Desktop Switcher

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut \
		Imlib2.3:${PORTSDIR}/graphics/imlib2

USE_GL=		yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		3ddesk.1 3ddeskd.1
PORTDOCS=	README README.windowmanagers
PLIST_FILES=	bin/3ddesk bin/3ddeskd etc/3ddesktop.conf \
		%%DATADIR%%/digits.bmp
PLIST_DIRS=	%%DATADIR%%

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O3||g ; \
		 s|@ACLOCAL@|${TRUE}|g ; \
		 s|@AUTOCONF@|${TRUE}|g ; \
		 s|@AUTOHEADER@|${TRUE}|g ; \
		 s|@AUTOMAKE@|${TRUE}|g'

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README README.windowmanagers
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
