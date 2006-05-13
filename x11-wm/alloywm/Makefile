# New ports collection makefile for:	alloywm
# Date created:				2002-01-20
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	alloywm
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.phatboydesigns.net/devel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Has title bars, shading, resizing, automatic placement, window list

HAS_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
REINPLACE_ARGS=	-i'' -E
SCRIPTS=	${WRKSRC}/scriptdir

pre-configure:
	${FIND} ${WRKSRC} \( -name '*.in' -or -name configure \) -exec \
		${REINPLACE_CMD} 's:bash:sh:g ; \
		s:gtk-config:${GTK_CONFIG}:g' {} \;
	${RM} -f ${WRKSRC}/*/Makefile
	${CHMOD} +x ${WRKSRC}/configure

do-build:
	cd ${WRKSRC}/goodies && ${GMAKE}
.for ii in client events main misc new screen widgets
	cd ${WRKSRC}/src && ${CC} -c ${CFLAGS} -I${X11BASE}/include \
		${ii}.c
.endfor
	cd ${WRKSRC}/src && ${CC} ${CFLAGS} -DSHAPE -o alloywm \
		-L${X11BASE}/lib -lXext -lX11 \
		client.o events.o main.o misc.o new.o screen.o widgets.o

pre-install:
	cd ${WRKSRC} && ${FIND} * -type f -perm 755 | cut -f 2 -d / | \
		${SED} "s:^:bin/:g" > ${PLIST}
	${FIND} ${SCRIPTS} \! -name '*in' -type f | \
		${SED} "s:^${SCRIPTS}:bin:g" >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in Changelog README
	${ECHO_CMD} share/doc/alloywm/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/alloywm >> ${PLIST}
.endif

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${WRKSRC}/README ${DOCSDIR}
.endif
	${FIND} ${SCRIPTS} \! -name '*in' -type f -exec \
		${INSTALL_SCRIPT}  {} ${PREFIX}/bin \;
	${FIND} ${WRKSRC} -type f -perm 755 \
		-exec ${INSTALL_PROGRAM} {} ${PREFIX}/bin \;

.include <bsd.port.pre.mk>
.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
.endif
.include <bsd.port.post.mk>
