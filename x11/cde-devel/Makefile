PORTNAME=	cde
PORTVERSION=	${COMMIT_DATE}
CATEGORIES=	x11
.if !defined(MASTERDIR)
PKGNAMESUFFIX=	-devel
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Common Desktop Environment
WWW=		https://sourceforge.net/p/cdesktopenv/wiki/Home/

USE_GITHUB=	yes
GH_ACCOUNT=	cschuber
GH_PROJECT=	cdesktopenv-code
GH_TAGNAME=	9f0f015c4
COMMIT_DATE=	2025.06.13

LICENSE=	LGPL21

BROKEN_i386=		cannot bind to a temporary of type va_list

WRKSRC_SUBDIR=	${PORTNAME}

BUILD_DEPENDS=	ksh93:shells/ksh			\
		bdftopcf:x11-fonts/bdftopcf		\
		mkfontscale>=0:x11-fonts/mkfontscale	\
		biconv:converters/iconv			\
		${LOCALBASE}/libdata/pkgconfig/fontconfig.pc:x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:print/freetype2 \
		onsgmls:textproc/opensp \
		xrdb:x11/xrdb \
		sessreg:x11/sessreg
RUN_DEPENDS=	ksh93:shells/ksh			\
		${LOCALBASE}/bin/fc-cache:x11-fonts/fontconfig \
		${LOCALBASE}/libdata/pkgconfig/freetype2.pc:print/freetype2 \
		xrdb:x11/xrdb \
		xset:x11/xset \
		sessreg:x11/sessreg
LIB_DEPENDS=	liblmdb.so:databases/lmdb

USES=		autoreconf:build iconv:wchar_t gmake jpeg libtool motif perl5 \
		shebangfix tcl:86 xorg
SHEBANG_LANG=	pl
SHEBANG_FILES=	programs/dtinfo/tools/bin/ccdate \
		programs/dtdocbook/tcl/docbook.tcl
DT_PREFIX=	${PREFIX}/dt
USE_LDCONFIG=	${DT_PREFIX}/lib
USE_RC_SUBR=	dtcms dtlogin
USE_XORG=	ice sm x11 xau xdmcp xext xinerama xmu xscrnsaver xt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${DT_PREFIX}
GNU_CONFIGURE_MANPREFIX=	${DT_PREFIX}/share
MANDIRS=	${DT_PREFIX}/share/man
INFODIR=	${DT_PREFIX}/share/info
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.6 MAKE="gmake" \
		--enable-german \
		--enable-italian \
		--enable-french \
		--enable-spanish \
		--enable-japanese
MAKE_ARGS+=	PERL=${PERL} "LOCAL_LDFLAGS=${LDFLAGS}"
MAKE_JOBS_UNSAFE=yes
MAKE_ENV=	MALLOC_CONF=junk:false
SUB_FILES=	pkg-message
CFLAGS+=	-Wno-register -Wno-incompatible-function-pointer-types \
		-Wno-implicit-function-declaration
LDFLAGS+=	-z muldefs #--allow-multiple-definition

CFFILES=	Xaccess Xconfig Xfailsafe Xreset Xservers Xsetup Xstartup \
		sys.dtprofile

pre-configure:
	@cd ${WRKSRC} && ./autogen.sh

post-patch:
	@if [ -f /usr/include/iconv.h ]; then \
	    ${REINPLACE_CMD} -e 's!^[[:space:]]*const char .ip = (const char .) .bp!char *ip = *bp!' \
	    ${WRKSRC}/programs/dtmail/libDtMail/Common/Session.C \
	    ${WRKSRC}/programs/dtmail/libDtMail/RFC/RFCBodyPart.C; \
	fi

# From shells/ksh93
	@${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/include/sfio*.h  \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/sfio/*.c \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/sfio/*.h

# Needed for armv6
	@${REINPLACE_CMD} -e 's|__va_copy|va_copy|g' \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/hash/*.c \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/sfio/*.c \
		${WRKSRC}/programs/dtksh/ksh93/src/lib/libast/string/*.c

# Fix all hardcoded path
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		${WRKSRC}/programs/dtinfo/tools/bin/ccdate
	@${FIND} ${WRKSRC} -type f ! -path doc/common | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/dt|${DT_PREFIX}|g ; \
		s|/etc/dt|${DT_PREFIX}/etc|g'

# we need to remove a few LOCALBASE
	@${REINPLACE_CMD} -e 's|${LOCALBASE}/etc/dtsr|/etc/dtsr|g' -e \
		's|${LOCALBASE}/etc/dtinfo_start|/etc/dtinfo_start|g' \
		${WRKSRC}/programs/tttypes/dtinfo_start.ptype \
		${WRKSRC}/programs/tttypes/dtinfo.ptype

# why redefine exit??
	@${REINPLACE_CMD} -e '/void exit/d' \
		${WRKSRC}/lib/tt/bin/tt_type_comp/frozen.mp_types_lex.C
# (time_t*) NULL is apparently too C-ish
	@${REINPLACE_CMD} -e 's,(time_t) *NULL,nullptr,' \
		${WRKSRC}/programs/dtmail/libDtMail/Common/FileShare.C \
		${WRKSRC}/programs/dtmail/libDtMail/RFC/RFCMailBox.C

# chown is not supported as install as user
	@${FIND} ${WRKSRC} -type f -name Makefile.am | ${XARGS} \
	${REINPLACE_CMD} -e '/chown /d; /chgrp /d;'

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/pam/libpam/pam.conf \
		${STAGEDIR}${PREFIX}/etc/pam.d/cde.conf
	@${ECHO_CMD} MANPATH /usr/local/dt/share/man >  ${STAGEDIR}/${PREFIX}/etc/man.d/cde.conf
	@${FIND} ${STAGEDIR}/${DT_PREFIX} -type f -exec ${SH} -c '${STRIP_CMD} {} > /dev/null 2>&1' \;
	@${FIND} ${STAGEDIR}/${DT_PREFIX} -type f -name '*.bak' -delete
	@cd ${WRKSRC}/examples && @${FIND} . | ${CPIO} -pd ${STAGEDIR}/${DT_PREFIX}/share
	@cd ${STAGEDIR}/${DT_PREFIX}; ${LN} -sf share/examples
	# Only a problem on armv7 so far
	${FIND} ${STAGEDIR}/${DT_PREFIX} -type f -name 'ecp.*' -delete
.for f in ${CFFILES}
	@${MV} ${STAGEDIR}${PREFIX}/dt/config/${f} ${STAGEDIR}${PREFIX}/dt/config/${f}.sample
.endfor

.include <bsd.port.mk>
