# New ports collection makefile for:	epiwm
# Date created:				2002-06-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	epiwm
PORTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.nongnu.org/epiwm/download/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Another fast, small, configurable window manager

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif

CONFIG=		icons key menu start style window workspace
DOCS=		AUTHORS BUGS COPYING ChangeLog EPIwm-0.5.6.lsm INSTALL NEWS \
		README TODO
PLIST=		${WRKDIR}/pkg-plist
USE_AUTOCONF_VER=	213
WANT_AUTOMAKE_VER=	14
USE_X_PREFIX=	yes

post-extract:
# Avoid having to read this file.
	${RM} ${WRKSRC}/configure

do-patch:
	${CP} -p ${WRKSRC}/configure.in ${WRKSRC}/configure.in.orig
	${SED} -e 's|/etc/X11/epiwm|${PREFIX}/etc/epiwm|' \
		< ${WRKSRC}/configure.in.orig > ${WRKSRC}/configure.in

pre-configure:
	cd ${WRKSRC} && automake14 -i && autoconf213

pre-install:
	${RM} -f ${PLIST}
.for ii in epiwm logoepiwm epiwm.inst
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
.for ii in ${CONFIG}
	${ECHO_CMD} etc/epiwm/${ii} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/epiwm/${ii} >> ${PLIST}
.endfor
.for ii in etc share/doc
	${ECHO_CMD} @dirrm ${ii}/epiwm >> ${PLIST}
.endfor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/epiwm \
		${WRKSRC}/modules/logoepiwm/logoepiwm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/epiwm.inst ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/epiwm
.for ii in ${CONFIG}
	${INSTALL_DATA} ${WRKSRC}/config/${ii} ${PREFIX}/etc/epiwm
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
