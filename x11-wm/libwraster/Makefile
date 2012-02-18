# New ports collection makefile for:	libwraster
# Date created:				August 17, 2009
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libwraster
PORTREVISION=	0

COMMENT=	libwraster from Window Maker

MASTERDIR=	${.CURDIR}/../windowmaker

LWR_SLAVE=	yes

PATCHDIR=	# To void equivalent in master port
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS=	windowmaker-0.*

post-patch:
	@${CP} ${WRKSRC}/wrlib/Makefile.in ${WRKSRC}/wrlib/Makefile.in.presed
	@${SED} -e s#$$\(libdir\)/pkgconfig#${PREFIX}/libdata/pkgconfig#g \
	    ${WRKSRC}/wrlib/Makefile.in.presed > ${WRKSRC}/wrlib/Makefile.in

do-build:
	cd ${WRKSRC} && ${MAKE} config-paths.h
	cd ${WRKSRC}/wrlib && ${MAKE}

do-install:
	cd ${WRKSRC}/wrlib && ${MAKE} install

.include "${MASTERDIR}/Makefile"
